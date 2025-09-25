# IBDA_IPV4Filter::GetMulticastMode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetMulticastMode** method retrieves the multicast mode.

## Parameters

### `pulModeMask` [out]

Pointer that receives the mask. See the Windows DDK for possible values.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPV4Filter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipv4filter)

[PutMulticastMode](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_ipv4filter-putmulticastmode)