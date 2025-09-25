# IMSVidCtl::Stop

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Stop** method stops the filter graph.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method leaves the filter graph intact and ready to pause or run. To tear down the filter graph, use the [IMSVidCtl::Decompose](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-decompose) method.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)