# IXpsSigningOptions::SetSigningTimeFormat

## Description

Sets the format of the signing time string.

## Parameters

### `timeFormat` [in]

The [OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format) value that specifies the format of the signing time string.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

For more information about the format of the date-time string that is passed in *timeFormat*, see [OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format).

If a signing time format has not been set, **OPC_SIGNATURE_TIME_FORMAT_MILLISECONDS** will be used as the default format.

## See also

[IOpcSigningOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcsigningoptions)

[IXpsSigningOptions](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssigningoptions)

[OPC_SIGNATURE_TIME_FORMAT](https://learn.microsoft.com/windows/win32/api/msopc/ne-msopc-opc_signature_time_format)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)