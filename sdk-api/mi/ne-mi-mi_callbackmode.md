# MI_CallbackMode enumeration

## Description

Defines the callback mode for the CIM extensions for **WriteError** and **PromptUser** functions.

## Constants

### `MI_CALLBACKMODE_REPORT`

Report the details to the client, but the provider will receive a preconfigured response. The provider does not wait for the client to receive the request before continuing.

### `MI_CALLBACKMODE_INQUIRE`

Query the client to determine whether the provider should continue.

### `MI_CALLBACKMODE_IGNORE`