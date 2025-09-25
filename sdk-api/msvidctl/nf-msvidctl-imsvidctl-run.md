# IMSVidCtl::Run

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Run** method runs the filter graph.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method builds the filter graph if the state is unbuilt, and puts the graph into the running state. For more information on the behavior of [Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build), [View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) and **Run**, see **IMSVidCtl::View**.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)