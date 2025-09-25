# IBDA_IPSinkControl::GetAdapterIPAddress

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This interface is available for use in the Microsoft Windows 2000, Windows XP, and Windows Server 2003 operating systems. It may be altered or unavailable in subsequent versions.

The **GetAdapterIPAddress** method retrieves the IP address of the NIC.

## Parameters

### `pulcbSize` [out]

Receives the length of the buffer, in bytes.

### `pbBuffer` [out]

Pointer to a byte array containing the address.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

**IBDA_IPSinkControl** is no longer being supported for Ring 3 clients. Use the **BDA_IPSinkInfo** interface instead.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPSinkControl Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipsinkcontrol)