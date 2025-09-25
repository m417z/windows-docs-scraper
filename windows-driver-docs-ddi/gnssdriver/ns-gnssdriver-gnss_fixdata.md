# GNSS_FIXDATA structure

## Description

The **GNSS_FIXDATA** structure defines the specific data elements associated with a GNSS fix returned from the driver.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `FixSessionID`

ID of the fix session that generated this fix.

The GNSS driver populates this field so that the GNSS adapter can correlate the fix data with the original start fix request.

### `FixTimeStamp`

Timestamp when the fix is generated.

This should be the time obtained from the satellites measurements.

### `IsFinalFix`

Boolean value indicating whether this is a final fix or not.

A value of FALSE implies this is an intermediate fix and a final fix is forthcoming.

### `FixStatus`

An NTSTATUS value indicating whether this fix contains a valid fix, or if the GNSS engine/driver encountered any error in getting the fix.

Unless this value indicates success, the basic fix data element of this structure should not be relied on. Satellite and mode data elements may still be valid.

### `FixLevelOfDetails`

A bitmask containing the GNSS_FIXDETAIL_* bits that determine which members of this structure are populated by the GNSS driver.

### `BasicData`

This element contains the basic fix data fix when FixLevelofDetails field has GNSS_FIXDETAIL_BASIC bit set.

Unless explicitly indicated in the fix session parameter, the GNSS driver is recommended to always populate this element.

### `AccuracyData`

This element contains the accuracy-related data when FixLevelofDetails field has GNSS_FIXDETAIL_ACCURACY bit set.

### `SatelliteData`

This element contains the satellite-related data when FixLevelofDetails field has GNSS_FIXDETAIL_SATELLITE bit set.