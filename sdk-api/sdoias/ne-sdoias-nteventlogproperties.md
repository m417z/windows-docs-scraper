# NTEVENTLOGPROPERTIES enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The values of the
**NTEVENTLOGPROPERTIES** enumeration type enumerate what types of events should be logged in the NT Event Log.

## Constants

### `PROPERTY_EVENTLOG_LOG_APPLICATION_EVENTS`

Specifies how the reporting of NPS Error events occurs in the Windows event log. In Windows XP, there is no UI element that corresponds to this property

### `PROPERTY_EVENTLOG_LOG_MALFORMED`

Specifies whether discarded and rejected packets are logged.

### `PROPERTY_EVENTLOG_LOG_DEBUG`

Specifies whether successful authentications are logged.