# EMI_MEASUREMENT_DATA_V2 structure

## Description

The EMI_MEASUREMENT_DATA_V2 structure provides data about the current energy
measurement data for all channels of an EMI_VERSION_V2 device. Each index in
ChannelData must correspond to the measurement of the channel defined at the
same index in Channels field of the EMI_METADATA_V2 struct.

## Members

### `ChannelData`

The channel measurement for each channel exposed by this device.