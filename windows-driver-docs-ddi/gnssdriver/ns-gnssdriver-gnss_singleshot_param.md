# GNSS_SINGLESHOT_PARAM structure

## Description

This structure defines the parameters for a single-shot fix session.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `ResponseTime`

Response time is maximum remaining time that an application can wait for a fix or an error.

Since the driver is expected to return intermediate fixes the ResponseTime is only an advisory information for the driver that can be used in an implementation-specific manner for making appropriate tradeoffs internally to satisfy the request. A value of 0 indicate that no specific response time is mandated by the GNSS adapter for the fix session.