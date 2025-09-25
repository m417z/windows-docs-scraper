# IMSVidCtl::get_InputsAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_InputsAvailable** method retrieves the input devices that are available within a specified category.

## Parameters

### `CategoryGuid` [in]

**BSTR** that specifies the GUID of the category to enumerate.

### `pVal` [out]

Receives an [IMSVidInputDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevices) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is provided for Automation clients. C++ applications can use the [IMSVidCtl::get__InputsAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get__inputsavailable) method, which takes a GUID rather than a **BSTR** value.

If the method succeeds, the [IMSVidInputDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevices) interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)