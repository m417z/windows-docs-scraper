# DVB_EIT_FILTER_OPTIONS structure

## Description

Specifies a section within a Digital Video Broadcast (DVB) Event Information Table (EIT) section header. Because the EIT can be quite large, these options allow applications to reduce load time by filtering specific segments from the EIT section header.

## Members

### `fSpecifySegment`

If this flag is **TRUE**, the number of the segment that is queried from the header must match the value of the **bSegment** structure member. Otherwise, the segment field is ignored.

### `bSegment`

Specifies the segment within the EIT section header that is queried.