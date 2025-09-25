# IWMCodecPrivateData::SetPartialOutputType

## Description

Gives the codec the output media type without the codec data. This enables the codec to generate the private data.

## Parameters

### `pmt` [in]

Address of the partial output media type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The DMO_MEDIA_TYPE that you pass to this method is only partial in that it does not include the appended private data. It must be complete in all other ways.

If you are setting properties on an encoder, you must finish that configuration before getting the private data. Changing properties invalidates any private data previously retrieved. If you change properties after getting the private data, retrieve it again and reset the output type.

You must call this method before calling [IWMCodecPrivateData::GetPrivateData](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmcodecprivatedata-getprivatedata) to get the private data.

## See also

[IWMCodecPrivateData Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecprivatedata)