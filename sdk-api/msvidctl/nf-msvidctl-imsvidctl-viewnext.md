# IMSVidCtl::ViewNext

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **ViewNext** method finds another input device to view the specified tune request.

This method is supported only for analog tuner devices. It does not work with digital tuners.

## Parameters

### `v` [in]

Specifies the tune request as a **VARIANT** type.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method works like the [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method, with the following difference: If the system has more than one tuner that supports the specified network type, the **ViewNext** method skips the current input device and uses the next one. (The ordering of devices is arbitrary.)

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view)