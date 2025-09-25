# IXDSCodecConfig::GetSecureChannelObject

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **GetSecureChannelObject** method retrieves the secure channel object used to decrypt the stream.

## Parameters

### `ppUnkDRMSecureChannel` [out]

Receives a pointer to the secure channel object's **IUnknown** interface.

## Return value

Returns an **HRESULT**.

## Remarks

If the method succeeds, the caller must release the **IUnknown** interface.

## See also

[IXDSCodecConfig Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ixdscodecconfig)