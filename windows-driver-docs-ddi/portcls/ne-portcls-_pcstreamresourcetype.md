# _PcStreamResourceType enumeration

## Description

This topic discusses the PcStreamResourceType enum, and describes its members. The PcStreamResourceType enum is used to define the type of resources used for specific audio streaming

## Constants

### `ePcStreamResourceInterrupt`

The resource is a PKINTERRUPT.

### `ePcStreamResourceThread`

 The resource is a PETHREAD.

### `ePcStreamResourceSet`

The resource is a link to another device-stack’s resources.

## Remarks

Stream resources are any resources used by the audio driver to process audio streams or ensure audio data flow. Two type of stream resources are supported: interrupts and driver-owned threads. Audio drivers should register a resource after creating the resource, and unregister the resource before deleted it.