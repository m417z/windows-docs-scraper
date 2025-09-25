# NOTIFYADD structure

## Description

The **NOTIFYADD** structure contains the details of a network connect operation. It is used by the
[AddConnectNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-addconnectnotify) function.

## Members

### `hwndOwner`

A handle to a window which should own any messages or dialog boxes the application receiving the notification might display.

### `NetResource`

Specifies the network resource to connect to. The valid fields are the same as for the
[NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection) function.

### `dwAddFlags`

Any combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONNECT_TEMPORARY** | The connection is being established for browsing purposes and may be released quickly. |
| **CONNECT_INTERACTIVE** | The connection may have interaction with the user. |
| **CONNECT_PROMPT** | Do not use any defaults without offering the user the chance to supply an alternative. This flag is valid only if CONNECT_INTERACTIVE is set. |
| **CONNECT_UPDATE_PROFILE** | The connection is being made persistent. |
| **CONNECT_UPDATE_RECENT** | The connection is being added to the recent connection list. |