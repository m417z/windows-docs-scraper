# IBDA_IPV6Filter::PutMulticastList

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **PutMulticastList** method specifies the parameters of the multicast list.

## Parameters

### `ulcbAddresses` [in]

Specifies the number of addresses in the list, multiplied by the number of bytes per address.

### `pAddressList` [in]

Pointer to an array of addresses whose size in bytes is equal to *ulcbAddresses*.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPV6Filter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipv6filter)