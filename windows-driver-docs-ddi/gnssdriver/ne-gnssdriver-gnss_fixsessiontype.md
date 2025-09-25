# GNSS_FIXSESSIONTYPE enumeration

## Description

This enumeration indicates the type of location fix needed by the GNSS adapter when it issues an [IOCTL_GNSS_START_FIXSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_start_fixsession) control code. This enumeration is set within the [GNSS_FIXSESSION_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_fixsession_param) structure.

## Constants

### `GNSS_FixSession_SingleShot`

The session request is a single-shot request. The GNSS driver will return intermediate fixes on request. Once a final fix is delivered, no further fix will be returned for this fix session and the GNSS adapter issues a stop fix.

### `GNSS_FixSession_DistanceTracking`

The start-fix request is for starting a tracking session such that a new fix is recorded and made available on request as soon as the device has moved beyond a specified threshold. No intermediate fix is required for a tracking session. A distance tracking session can be started even when another fix session of a different type is active. Both the fix sessions will continue getting the fixes as appropriate.

### `GNSS_FixSession_ContinuousTracking`

The start fix request is for starting a tracking session such that the device position is reported continuously.

### `GNSS_FixSession_LKG`

This session request is for a single-shot request, without starting any satellite acquisition/tracking activity by the underlying GNSS engine. The GNSS driver returns the cached copy (either from the engine or from the drivers own memory) of the last known position of the device, along with the timestamp. If no cached fix is available either in the engine or in the driver, an error is returned. No intermediate fix is returned for this session. Once the LKG fix or an error fix is returned the GNSS adapter issues a stop fix.