# CPEvents enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP Service Pack 1 or later.

The **CPEvents** enumeration defines copy protection events for the Decrypter/Detagger filter. This enumeration is used with the EVENTID_EncDecFilterEvent event. For more information, see [TV Ratings Broadcast Events](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tv-ratings-broadcast-events).

## Constants

### `CPEVENT_NONE:0`

No content protection issues.

### `CPEVENT_RATINGS`

Content is blocked because of parental ratings.

### `CPEVENT_COPP`

Content is blocked because of copy protection rules.

### `CPEVENT_LICENSE`

Content is blocked because the DRM license is not valid.

### `CPEVENT_ROLLBACK`

Content is blocked because the system detected that the clock was rolled back.

### `CPEVENT_SAC`

Content is blocked because the filter graph contains untrusted components.

### `CPEVENT_DOWNRES`

Content is being rendered at a lower resolution due to copy protection.

### `CPEVENT_STUBLIB`

Content is blocked because the filter graph contains untrusted components.

### `CPEVENT_UNTRUSTEDGRAPH`

Content is blocked because the filter graph contains untrusted components.

### `CPEVENT_PROTECTWINDOWED`

## See also

[TV Ratings Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tv-ratings-enumerations)