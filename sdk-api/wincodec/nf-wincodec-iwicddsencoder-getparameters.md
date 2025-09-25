# IWICDdsEncoder::GetParameters

## Description

Gets DDS-specific data.

## Parameters

### `pParameters` [out]

Type: **[WICDdsParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters)***

Points to the structure where the information is returned.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An application can call **GetParameters** to obtain the default DDS parameters, modify some or all of them, and then call [SetParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicddsencoder-setparameters).

## See also

[IWICDdsEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicddsencoder)

[WICDdsParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters)