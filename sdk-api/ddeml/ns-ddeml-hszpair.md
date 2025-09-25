# HSZPAIR structure

## Description

Contains a DDE service name and topic name. A DDE server application can use this structure during an [XTYP_WILDCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-wildconnect) transaction to enumerate the service-topic pairs that it supports.

## Members

### `hszSvc`

Type: **HSZ**

A handle to the service name.

### `hszTopic`

Type: **HSZ**

A handle to the topic name.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)