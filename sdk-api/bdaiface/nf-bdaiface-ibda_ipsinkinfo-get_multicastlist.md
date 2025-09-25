# IBDA_IPSinkInfo::get_MulticastList

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This interface is available for use in the Microsoft Windows 2000, Windows XP, and Windows Server 2003 operating systems. It may be altered or unavailable in subsequent versions.

The **get_MulticastList** method retrieves a list of the multicast addresses to which the IP Sink filter is listening. This method returns a list of IP addresses in 6-byte IEEE 802.3 format; the list is returned as an array of bytes.

## Parameters

### `pulcbAddresses` [out]

Receives the number of bytes in the returned array.

### `ppbAddressList` [out]

Pointer to variable that receives an array of bytes, of size **pulcbAddresses*. Each IP address is 6 consecutive bytes.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The method allocates the memory for the array. The caller must free the memory by calling **CoTaskMemFree**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPSinkInfo Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipsinkinfo)