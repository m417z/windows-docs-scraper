# _IRB_REQ_ISOCH_ALLOCATE_CHANNEL structure

## Description

This structure contains the fields necessary in order for the 1394 bus driver to carry out an IsochAllocateChannel request.

## Members

### `nRequestedChannel`

Specifies the particular channel to allocate, or ISOCH_ANY_CHANNEL for an arbitrary channel.

### `Channel`

Specifies the channel allocated, if the request succeeds.

### `ChannelsAvailable`

A bitmap specifying the available channels. The highest order bit (bit 63) specifies channel 0, the next bit (bit 62) specifies channel 1, and so on.

**Note** Drivers should not rely on this information because another device may allocate or deallocate channels at any time. The bus driver fills in this member, even if the request fails.