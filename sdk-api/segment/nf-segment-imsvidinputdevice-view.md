# IMSVidInputDevice::View

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **View** method configures this input device to view the specified tune request.

## Parameters

### `v` [in]

Specifies the tune request as a **VARIANT** type.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Before calling this method, set the device as the active input by calling the [IMSVidCtl::put_InputActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_inputactive) method. Unless the application needs to choose a specific input device, however, the [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method is recommended instead of the **IMSVidInputDevice::View** method.

## See also

[IMSVidInputDevice Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevice)