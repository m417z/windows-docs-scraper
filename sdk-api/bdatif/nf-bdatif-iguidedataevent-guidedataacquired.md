# IGuideDataEvent::GuideDataAcquired

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GuideDataAcquired** method is called when a complete set of guide data has been acquired from the current transport stream.

Currently the [BDA MPEG-2 Transport Information Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-mpeg-2-transport-information-filter) (TIF) does not support this event, so this method is not called.

## Return value

Return S_OK if successful, or an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGuideDataEvent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataevent)