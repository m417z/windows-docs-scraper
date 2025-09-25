# IMSVidCtl::put_InputActive

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_InputActive** method specifies the input device to use in the filter graph.

## Parameters

### `pVal` [in]

Specifies a pointer to the input device's [IMSVidInputDevice](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevice) interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the Video Control's state is not **STATE_UNBUILT**, call the [IMSVidCtl::Decompose](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-decompose) to tear down the filter graph before calling this method.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_InputActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_inputactive)

[IMSVidCtl::get_State](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_state)