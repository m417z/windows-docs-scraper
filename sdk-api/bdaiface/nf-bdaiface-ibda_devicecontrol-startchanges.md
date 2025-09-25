# IBDA_DeviceControl::StartChanges

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **StartChanges** method is called by a Network Provider before it begins to modify a set of properties on a BDA device filter.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The device filter validates and accumulates all changes requested after **StartChanges**. It makes the accumulated list of changes when **CommitChanges** is called.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_DeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_devicecontrol)