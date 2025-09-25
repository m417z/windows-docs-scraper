# IWMCodecPrivateData::GetPrivateData

## Description

Retrieves the codec data for the video content based on the output type passed using the [IWMCodecPrivateData::SetPartialOutputType](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmcodecprivatedata-setpartialoutputtype) method.

## Parameters

### `pbData` [out]

Address of the buffer that receives the private data. If you set this to **NULL**, the size required to hold the private data will be returned in *pcbData*.

### `pcbData` [in, out]

Pointer to the size of the private data in bytes. If pbData is **NULL**, the method will set this to the correct value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If you are setting properties on the encoder object, you must finish that configuration before getting the private data. Changing properties invalidates any private data that was previously retrieved. If you change properties after getting the private data, retrieve it again and reset the output type.

You must call this method after providing the codec with the output media type (without the private data appended) by calling [IWMCodecPrivateData::SetPartialOutputType](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmcodecprivatedata-setpartialoutputtype).

After retrieving the private data, allocate a buffer the size of VIDEOINFOHEADER plus *pcbData*. Then copy the data from your partial output type to the beginning of the buffer and append the private data.

## See also

[IWMCodecPrivateData Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecprivatedata)