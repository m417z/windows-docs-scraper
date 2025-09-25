# IBDA_UserActivityService::UserActivityDetected

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Indicates that a Media Sink Device (MSD) in a Protected Broadcast Driver Architecture (PBDA) media graph has detected user activity and is informing a Media Transfer Device (MTD) of this activity. The MSD calls this method only if the current activity interval has elapsed since the the MSD most recently called this method. The [GetUserActivityInterval](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_useractivityservice-getuseractivityinterval) method sets or obtains the value of the current activity interval.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOINTERFACE** | User activity service failed. |

## See also

[GetUserActivityInterval](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_useractivityservice-getuseractivityinterval)

[IBDA_UserActivityService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_useractivityservice)