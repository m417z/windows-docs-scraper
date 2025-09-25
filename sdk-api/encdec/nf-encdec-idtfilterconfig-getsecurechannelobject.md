# IDTFilterConfig::GetSecureChannelObject

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetSecureChannelObject** method retrieves the secure channel object used to decrypt the stream.

## Parameters

### `ppUnkDRMSecureChannel` [out]

Receives a pointer to the secure channel object's **IUnknown** interface.

## Return value

Returns an **HRESULT**.

## Remarks

If the method succeeds, the caller must release the **IUnknown** interface.

## See also

[IDTFilterConfig Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilterconfig)