# _IRB_REQ_ISOCH_QUERY_RESOURCES structure

## Description

This structure contains the fields necessary to carry out a IsochQueryResources request.

## Members

### `fulSpeed`

Specifies the speed flag to use in allocating bandwidth. The possible speed values are SPEED_FLAGS_xxx, where xxx is the approximate transfer rate in megabits per second. Existing hardware supports transfer rates of 100, 200, and 400 MBps.

| Transfer Rate | Description |
| --- | --- |
| SPEED_FLAGS_100 | 100 Mb/s |
| SPEED_FLAGS_200 | 200 Mb/s |
| SPEED_FLAGS_400 | 400 Mb/s |

### `BytesPerFrameAvailable`

On success, specifies the returned available bandwidth as expressed in bytes per isochronous frame.

### `ChannelsAvailable`

On success, points to a bitmap of available channels.

 The highest order bit (bit 63) specifies channel 0, the next bit (bit 62) specifies channel 1, and so on.