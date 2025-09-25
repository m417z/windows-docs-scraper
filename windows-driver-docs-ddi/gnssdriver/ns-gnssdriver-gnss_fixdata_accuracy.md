# GNSS_FIXDATA_ACCURACY structure

## Description

The **GNSS_FIXDATA_ACCURACY** structure defines the accuracy details of a fix.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `HorizontalAccuracy`

Accuracy reported with 95% confidence.

### `HorizontalErrorMajorAxis`

Horizontal uncertainty ellipse semi-major axis with 95% confidence accuracy.

### `HorizontalErrorMinorAxis`

Horizontal uncertainty ellipse semi-minor axis with 95% confidence accuracy.

### `HorizontalErrorAngle`

Horizontal uncertainty ellipse orientation angle with 95% confidence accuracy.

### `HeadingAccuracy`

Reserved, do not use.

### `AltitudeAccuracy`

Reserved, do not use.

### `SpeedAccuracy`

Reserved, do not use.

### `HorizontalConfidence`

Reserved, do not use.

### `HeadingConfidence`

Reserved, do not use.

### `AltitudeConfidence`

Reserved, do not use.

### `SpeedConfidence`

Reserved, do not use.

### `PositionDilutionOfPrecision`

Position dilution of precision (PDOP).

Satellite-based positions with a dilution of precision (DOP) value of 0 or a DOP value higher than 10 may be filtered by the GNSS adapter.

### `HorizontalDilutionOfPrecision`

Horizontal dilution of precision (HDOP).

### `VerticalDilutionOfPrecision`

Vertical dilution of precision (VDOP).