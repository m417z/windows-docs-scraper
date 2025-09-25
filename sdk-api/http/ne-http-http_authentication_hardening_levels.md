# HTTP_AUTHENTICATION_HARDENING_LEVELS enumeration

## Description

Server Hardening level.

## Constants

### `HttpAuthenticationHardeningLegacy:0`

Server is not hardened and operates without Channel Binding Token (CBT) support.

### `HttpAuthenticationHardeningMedium`

Server is partially hardened. Clients that support CBT are serviced appropriately. Legacy clients are also serviced.

### `HttpAuthenticationHardeningStrict`

Server is hardened. Only clients that supported CBT are serviced.