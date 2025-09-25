# IBDA_IPSinkInfo::get_AdapterDescription

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This interface is available for use in the Microsoft Windows 2000, Windows XP, and Windows Server 2003 operating systems. It may be altered or unavailable in subsequent versions.

The **get_AdapterDescription** method retrieves the description of the network adapter.

## Parameters

### `pbstrBuffer` [out]

Pointer to a **BSTR** that receives the description.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The caller must free the returned string, using the **SysFreeString** method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPSinkInfo Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipsinkinfo)