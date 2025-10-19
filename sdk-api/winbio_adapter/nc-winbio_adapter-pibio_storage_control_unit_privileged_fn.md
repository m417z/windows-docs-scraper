# PIBIO_STORAGE_CONTROL_UNIT_PRIVILEGED_FN callback function

## Description

Called by the Windows Biometric Framework to perform a vendor-defined control operation that requires elevated privilege. Call the [StorageAdapterControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_control_unit_fn) function to perform a vendor-defined control operation that does not require elevated privilege.

## Parameters

### `Pipeline` [in, out]

A pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `ControlCode` [in]

A **ULONG** value that specifies the vendor-defined operation to perform.

### `SendBuffer` [in]

A pointer to a buffer that contains the control information sent to the storage adapter. The format and content of the buffer is vendor defined.

### `SendBufferSize` [in]

The size, in bytes, of the buffer specified by the *SendBuffer* parameter.

### `ReceiveBuffer` [in]

A pointer to a buffer that receives information returned by the storage adapter in response to the control operation. The format of the buffer is vendor defined.

### `ReceiveBufferSize` [in]

The size, in bytes, of the buffer specified by the *ReceiveBuffer* parameter.

### `ReceiveDataSize` [out]

A pointer to a variable that receives the size, in bytes, of the data written to the buffer specified by the *ReceiveBuffer* parameter.

### `OperationStatus` [out]

A pointer to a variable that receives a vendor-defined status code that specifies the outcome of the control operation.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **E_INVALIDARG** | The size or format of the buffer specified by the *SendBuffer* parameter is not correct, or the value specified in the *ControlCode* parameter is not recognized by the adapter. |
| **E_NOT_SUFFICIENT_BUFFER** | The buffer specified by the *ReceiveBuffer* parameter is too small. |
| **WINBIO_E_CANCELED** | The operation was canceled. |
| **WINBIO_E_DEVICE_FAILURE** | There was a hardware failure. |
| **WINBIO_E_INVALID_CONTROL_CODE** | The value specified in the *ControlCode* parameter is not recognized by the adapter.<br><br>**Note** Beginning with Windows 8, use only **E_INVALIDARG** to signal this condition. |

## Remarks

Your implementation of this function should be identical to your implementation of the [StorageAdapterControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_control_unit_fn) function except that elevated privileges are required to perform the operations specified by the *ControlCode* parameter. You are responsible for defining the operations and deciding which will require elevated privilege.

This function must check the value of the *ReceiveBufferSize* parameter to be certain that the buffer specified by the *ReceiveBuffer* parameter is large enough to hold the data being returned.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterControlUnitPrivileged
//
// Purpose:
//      Performs a vendor-defined control operation that requires elevated privilege.
//
// Parameters:
//      Pipeline            - Pointer to a WINBIO_PIPELINE structure associated
//                            with the biometric unit performing the operation
//      ControlCode         - Specifies the vendor-defined operation to perform
//      SendBuffer          - Contains the control information sent to the
//                            storage adapter
//      SendBufferSize      - Size, in bytes, of the buffer specified by the
//                            SendBuffer parameter
//      ReceiveBuffer       - Receives information returned by the storage adapter
//                            in response to the control operation
//      ReceiveBufferSize   - Size, in bytes, of the buffer specified by the
//                            ReceiveBuffer parameter.
//      ReceiveDataSize     - Receives the size, in bytes, of the data written to
//                            the buffer specified by the ReceiveBuffer parameter
//      OperationStatus     - Receives a vendor-defined status code that specifies
//                            the outcome of the control operation.
//
static HRESULT
WINAPI
StorageAdapterControlUnitPrivileged(
    __inout PWINBIO_PIPELINE Pipeline,
    __in ULONG ControlCode,
    __in PUCHAR SendBuffer,
    __in SIZE_T SendBufferSize,
    __in PUCHAR ReceiveBuffer,
    __in SIZE_T ReceiveBufferSize,
    __out PSIZE_T ReceiveDataSize,
    __out PULONG OperationStatus
    )
{
    HRESULT hr = S_OK;
    BOOL result = TRUE;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(SendBuffer) ||
        !ARGUMENT_PRESENT(ReceiveBuffer) ||
        !ARGUMENT_PRESENT(ReceiveDataSize) ||
        !ARGUMENT_PRESENT(OperationStatus))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_STORAGE_CONTEXT storageContext =
           (PWINBIO_STORAGE_CONTEXT)Pipeline->StorageContext;

    // Verify the state of the pipeline.
    if (storageContext == NULL ||
        Pipeline->StorageHandle == INVALID_HANDLE_VALUE)
    {
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    switch (ControlCode)
    {
    case MY_PRIVILEGED_CTRL_CODE_P1:
        {
            CTRL_CODE_P1_SEND_BUFFER *sendBuffer = (CTRL_CODE_P1_SEND_BUFFER*)SendBuffer;

            // Verify the size of the send buffer.
            if (SendBufferSize < sizeof(CTRL_CODE_P1_SEND_BUFFER))
            {
                hr = E_INVALIDARG;
                break;
            }

            // Perform any other checks that may be required on the buffer
            // contents. Return E_INVALIDARG if any of the checks fail.
            if (sendBuffer->SomeField != SomeSpecialValue ||
                sendBuffer->SomeOtherField != SomeOtherSpecialValue)
            {
                hr = E_INVALIDARG;
                break;
            }

            if (ReceiveBufferSize < sizeof(CTRL_CODE_P1_RECEIVE_BUFFER))
            {
                hr = E_NOT_SUFFICIENT_BUFFER;
                break;
            }
        }

        // Fall through and perform the control operation after the switch
        // statement. Alternatively, depending on your requirements, you can
        // perform the control operation here.
        break;

    case MY_PRIVILEGED_CTRL_CODE_P2:
        // Continue testing for other non-privileged control codes that your
        // adapter supports.
        {
            CTRL_CODE_P2_SEND_BUFFER *sendBuffer = (CTRL_CODE_P2_SEND_BUFFER*)SendBuffer;

            // Verify the size of the send buffer.
            if (SendBufferSize < sizeof(CTRL_CODE_P2_SEND_BUFFER))
            {
                hr = E_INVALIDARG;
                break;
            }

            // Perform any other checks that may be required on the buffer
            // contents. Return E_INVALIDARG if any of the checks fail.
            if (sendBuffer->SomeField != SomeSpecialValue ||
                sendBuffer->SomeOtherField != SomeOtherSpecialValue)
            {
                hr = E_INVALIDARG;
                break;
            }

            if (ReceiveBufferSize < sizeof(CTRL_CODE_P2_RECEIVE_BUFFER))
            {
                hr = E_NOT_SUFFICIENT_BUFFER;
                break;
            }
        }
        break;

    default:
        // All unrecognized control code values should return an error.
        hr = WINBIO_E_INVALID_CONTROL_CODE;
        break;
    }
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // If control code validation succeeds, perform the control operation. This
    // example assumes that your adapter has put an open handle to a storage
    // device in the Pipeline structure. It also assumes that the driver performs
    // overlapped I/O and that a properly initialized OVERLAPPED structure is
    // contained in the storage context.
    result = DeviceIoControl(
                Pipeline->StorageHandle,
                ControlCode,
                SendBuffer,
                (DWORD)SendBufferSize,
                ReceiveBuffer,
                (DWORD)ReceiveBufferSize,
                (LPDWORD)ReceiveDataSize,
                &storageContext->Overlapped
                );
    if (result == FALSE && GetLastError() == ERROR_IO_PENDING)
    {
        SetLastError(ERROR_SUCCESS);

        result = GetOverlappedResult(
                    Pipeline->StorageHandle,
                    &storageContext->Overlapped,
                    (LPDWORD)ReceiveDataSize,
                    TRUE
                    );
    }
    *OperationStatus = GetLastError();

    if (!result)
    {
        hr = _AdapterGetHresultFromWin32(*OperationStatus);
    }

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterControlUnit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_control_unit_fn)