# ACTCTX_REQUESTED_RUN_LEVEL enumeration

## Description

The **ACTCTX_REQUESTED_RUN_LEVEL** enumeration describes the requested run level of the activation context.

## Constants

### `ACTCTX_RUN_LEVEL_UNSPECIFIED:0`

The application manifest does not specify a requested run level for the application.

### `ACTCTX_RUN_LEVEL_AS_INVOKER`

The application manifest requests the least privilege level to run the application.

### `ACTCTX_RUN_LEVEL_HIGHEST_AVAILABLE`

The application manifest requests the highest privilege level to run the application.

### `ACTCTX_RUN_LEVEL_REQUIRE_ADMIN`

The application manifest requests the administrator privilege level to run the application.

### `ACTCTX_RUN_LEVEL_NUMBERS`

Total number of possible run levels.