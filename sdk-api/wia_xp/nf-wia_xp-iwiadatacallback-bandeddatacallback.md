# IWiaDataCallback::BandedDataCallback

## Description

Provides data transfer status notifications. Windows Image Acquisition (WIA) data transfer methods of the [IWiaDataTransfer](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatatransfer) interface periodically call this method.

## Parameters

### `lMessage` [in]

Type: **LONG**

Specifies a constant that indicates the reason for the callback. Can be one of the following values:

#### IT_MSG_DATA

The WIA system is transferring data to the application.

#### IT_MSG_DATA_HEADER

The application is receiving a header prior to receiving the actual data.

#### IT_MSG_DEVICE_STATUS

Windows Vista or later. Status at the device has changed.

#### IT_MSG_FILE_PREVIEW_DATA

The WIA system is transferring preview data to the application.

#### IT_MSG_FILE_PREVIEW_DATA_HEADER

The application is receiving a header prior to receiving the actual preview data.

#### IT_MSG_NEW_PAGE

The data transfer is beginning a new page.

#### IT_MSG_STATUS

This invocation of the callback is sending only status information.

#### IT_MSG_TERMINATION

The data transfer is complete.

### `lStatus` [in]

Type: **LONG**

Specifies a constant that indicates the status of the WIA device. Can be set to a combination of the following:

#### IT_STATUS_TRANSFER_FROM_DEVICE

Data is currently being transferred from the WIA device.

#### IT_STATUS_PROCESSING_DATA

Data is currently being processed.

#### IT_STATUS_TRANSFER_TO_CLIENT

Data is currently being transferred to the client's data buffer.

### `lPercentComplete` [in]

Type: **LONG**

Specifies the percentage of the total data that has been transferred so far.

### `lOffset` [in]

Type: **LONG**

Specifies an offset, in bytes, from the beginning of the buffer where the current band of data begins.

### `lLength` [in]

Type: **LONG**

Specifies the length, in bytes, of the current band of data.

### `lReserved` [in]

Type: **LONG**

Reserved for internal use by the WIA run-time system.

### `lResLength` [in]

Type: **LONG**

Reserved for internal use by the WIA run-time system.

### `pbBuffer` [in]

Type: **BYTE***

Pointer to the data buffer.

## Return value

Type: **HRESULT**

If the method succeeds, the method returns S_OK. To cancel the data transfer, it returns S_FALSE. If the method fails, it returns a standard COM error code.

## Remarks

Your application must provide the **IWiaDataCallback::BandedDataCallback** method. This method is periodically invoked by the data transfer methods of the [IWiaDataTransfer](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatatransfer) interface. It provides status messages to the application during the data transfer. By returning S_FALSE, your program can also use this method to prematurely terminate the data transfer.

When this method is invoked, the *lMessage* parameter will contain the reason for the call. Not all parameters will contain data on all calls. For example, when **IWiaDataCallback::BandedDataCallback** is invoked with a message of IT_MSG_TERMINATION, it should not attempt to use the values in the *pbBuffer*, *lOffset*, and *lLength* parameters.

If the value of *lMessage* is IT_MSG_DATA, the buffer pointed to by *pbBuffer* contains a band of image data. The *lOffset* parameter contains an offset in bytes from the beginning of the buffer where the current band of data begins. The *lLength* parameter specified the length in bytes of the current band of data.

During calls where *lMessage* is set to IT_MSG_DATA or IT_MSG_STATUS, the *lStatus* parameter contains a valid value. Its contents should not be used when *lMessage* contains other values.

If *lMessage* is IT_MSG_DATA_HEADER, the *pbBuffer* parameter points to a [WIA_DATA_CALLBACK_HEADER](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_data_callback_header) structure.

When an error has occurred during an image data transfer, the driver sets *lMessage* to IT_MSG_DEVICE_STATUS. The proxy callback object calls [ReportStatus](https://learn.microsoft.com/windows/desktop/wia/-wia-iwiaerrorhandler-reportstatus), which handles the error and displays messages to the user.

#### Examples

The following example shows one possible way to implement the **IWiaDataCallback::BandedDataCallback** method.

The example application code defines the **CDataCallback** object that it derives from the [IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback) interface. The application must instantiate a **CDataCallback** object. It then calls **CDataCallback::QueryInterface** to obtain an **IWiaDataCallback** interface pointer. When the application is ready to receive data, it invokes the [idtGetBandedData](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetbandeddata) method and passes the method a pointer to the **IWiaDataCallback** interface.

Periodically, the [idtGetBandedData](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetbandeddata) method uses the [IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback) interface pointer to invoke the **CDataCallback::BandedDataCallback** method of the application. The first invocations send status messages. These are followed by a call that transfers a data header to the callback method. After the application receives the data header, **idtGetBandedData** invokes **CDataCallback::BandedDataCallback** to transfer data to the application. When the data transfer is complete, it calls the callback method a final time to transmit a termination message.

```cpp

//
// The application must instantiate the CDataCallback object using
// the "new" operator, and call QueryInterface to retrieve the
// IWiaDataCallback interface.
//
// In this example, using in-memory transfer, the application then
// calls the IWiaDataTransfer::idtGetBandedData method and passes
// it the IWiaDataCallback interface pointer.
//
// If the application performs a file transfer using
// IWiaDataTransfer::idtGetData, only status messages are sent,
// and the data is transferred in a file.
//
class CDataCallback : public IWiaDataCallback
{
private:
    LONG  m_cRef;               // Object reference count
    PBYTE m_pBuffer;            // Data buffer
    LONG  m_nBufferLength;      // Length of buffer
    LONG  m_nBytesTransfered;   // Total number of bytes transferred
    GUID  m_guidFormat;         // Data format

public:

    //
    // Constructor and destructor
    //
    CDataCallback()
      : m_cRef(1),
        m_pBuffer(NULL),
        m_nBufferLength(0),
        m_nBytesTransfered(0),
        m_guidFormat(IID_NULL)
    {
    }
    ~CDataCallback()
    {
        //
        // Free the item buffer
        //
        if (m_pBuffer)
        {
            LocalFree( m_pBuffer );
            m_pBuffer = NULL;
        }
        m_nBufferLength = 0;
        m_nBytesTransfered = 0;
    }

    //
    // IUnknown methods
    //
    HRESULT CALLBACK QueryInterface( REFIID riid, void **ppvObject )
    {
        //
        // Validate arguments
        //
        if (NULL == ppvObject)
        {
            return E_INVALIDARG;
        }

        //
        // Return the appropriate interface
        //
        if (IsEqualIID( riid, IID_IUnknown ))
        {
            *ppvObject = static_cast<CDataCallback *>(this);
        }
        else if (IsEqualIID( riid, IID_IWiaDataCallback ))
        {
            *ppvObject = static_cast<CDataCallback *>(this);
        }
        else
        {
            *ppvObject = NULL;
            return(E_NOINTERFACE);
        }

        //
        // Increment the reference count before returning the interface.
        //
        reinterpret_cast<IUnknown*>(*ppvObject)->AddRef();
        return S_OK;
    }
    ULONG CALLBACK AddRef()
    {
        return InterlockedIncrement(&m_cRef);
    }
    ULONG CALLBACK Release()
    {
        LONG cRef = InterlockedDecrement(&m_cRef);
        if (0 == cRef)
        {
            delete this;
        }
        return cRef;
    }

    //
    // The IWiaDataTransfer::idtGetBandedData method periodically
    // calls the IWiaDataCallback::BandedDataCallback method with
    // status messages. It sends the callback method a data header
    // message followed by one or more data messages to transfer
    // data. It concludes by sending a termination message.
    //

    HRESULT _stdcall BandedDataCallback(
            LONG lMessage,
            LONG lStatus,
            LONG lPercentComplete,
            LONG lOffset,
            LONG lLength,
            LONG lReserved,
            LONG lResLength,
            BYTE *pbData)
    {
        UNREFERENCED_PARAMETER(lReserved);
        UNREFERENCED_PARAMETER(lResLength);
        switch (lMessage)
        {
        case IT_MSG_DATA_HEADER:
            {
                //
                // The data header contains the image's final size.
                //
                PWIA_DATA_CALLBACK_HEADER pHeader = reinterpret_cast(pbData);
                if (pHeader && pHeader->lBufferSize)
                {
                    //
                    // Allocate a block of memory to hold the image
                    //
                    m_pBuffer = reinterpret_cast(LocalAlloc(LPTR,pHeader->lBufferSize));
                    if (m_pBuffer)
                    {
                        //
                        // Save the buffer size.
                        //
                        m_nBufferLength = pHeader->lBufferSize;

                        //
                        // Initialize the bytes transferred count.
                        //
                        m_nBytesTransfered = 0;

                        //
                        // Save the file format.
                        //
                        m_guidFormat = pHeader->guidFormatID;
                    }
                }
            }
            break;

        case IT_MSG_DATA:
            {
                //
                // Make sure a block of memory has been created.
                //
                if (NULL != m_pBuffer)
                {
                    //
                    // Copy the new band.
                    //
                    CopyMemory( m_pBuffer + lOffset, pbData, lLength );

                    //
                    // Increment the byte count.
                    //
                    m_nBytesTransfered += lLength;
                }
            }
            break;

        case IT_MSG_STATUS:
            {
                //
                // Display transfer phase
                //
                if (lStatus & IT_STATUS_TRANSFER_FROM_DEVICE)
                {
                    _tprintf(TEXT("Transfer from device\n"));
                }
                else if (lStatus & IT_STATUS_PROCESSING_DATA)
                {
                    _tprintf(TEXT("Processing Data\n"));
                }
                else if (lStatus & IT_STATUS_TRANSFER_TO_CLIENT)
                {
                    _tprintf(TEXT("Transfer to Client\n"));
                }

                //
                // Display percent complete
                //
                _tprintf( TEXT("lPercentComplete: %d\n"), lPercentComplete );
            }
            break;
        }

        return S_OK;
    }
};

```