# IBDA_IPV4Filter::GetMulticastList

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetMulticastList** method retrieves the list of multicast addresses on the Network Provider.

## Parameters

### `pulcbAddresses` [in, out]

On input, specifies the maximum number of addresses to retrieve, multiplied by the number of bytes per address. On output, receives the actual number of bytes retrieved.

### `pAddressList` [out]

Pointer that receives an array of addresses whose size in bytes is equal to *ulcbAddresses*.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The declaration of *pAddressList* is not COM compliant. As a workaround, the client should allocate the *pAddressList* buffer. The buffer should be the same size as advertised in the *pulcbAddresses* parameter. The network provider will just fill in the buffer allocated by the caller.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPV4Filter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipv4filter)