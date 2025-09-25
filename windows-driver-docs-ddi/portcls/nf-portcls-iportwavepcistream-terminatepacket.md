# IPortWavePciStream::TerminatePacket

## Description

The `TerminatePacket` method terminates the packet currently being mapped.

## Return value

`TerminatePacket` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

This method is used primarily for capture situations in which I/O packets need to end at specific points in the stream (for example, to synchronize with video frames). The data buffer for a capture pin on an audio device consists of one or more I/O packets. Each I/O packet is the portion of the data buffer that is attached to a particular mapping IRP. By default, while a capture stream is in the KSSTATE_RUN state, the contents of an I/O packet become available to the client only when the last mapping in the packet has been filled. The `TerminatePacket` method makes a partially filled packet immediately available to the client without waiting for additional capture data.

Changing the state of a capture stream from KSSTATE_RUN to KSSTATE_STOP automatically terminates the current I/O packet.