# IMSVidCtl::Build

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Build** method builds the filter graph and connects all the filters.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method builds a filter graph using the current input device. To select an input device, call the [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method or the [IMSVidCtl::put_InputActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_inputactive) method. If no input device has been selected, the method fails.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::Decompose](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-decompose)