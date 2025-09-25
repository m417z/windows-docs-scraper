# ACCOUNTINGPROPERTIES enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The values of the
**ACCOUNTINGPROPERTIES** type enumerate properties that control what types of packets are logged and characteristics of the log file.

## Constants

### `PROPERTY_ACCOUNTING_LOG_ACCOUNTING`

Specifies whether accounting packets are logged.

### `PROPERTY_ACCOUNTING_LOG_ACCOUNTING_INTERIM`

Specifies whether interim accounting packets are logged.

### `PROPERTY_ACCOUNTING_LOG_AUTHENTICATION`

Specifies whether authentication packets are logged.

### `PROPERTY_ACCOUNTING_LOG_OPEN_NEW_FREQUENCY`

Specifies how frequently a new log file is created. This property takes a value from the
[NEW_LOG_FILE_FREQUENCY](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-new_log_file_frequency) enumeration type.

### `PROPERTY_ACCOUNTING_LOG_OPEN_NEW_SIZE`

Specifies a file size. The system creates a new log file if the current log file reaches this size, and the **PROPERTY_ACCOUNTING_LOG_OPEN_NEW_FREQUENCY** property is set to the value
[IAS_LOGGING_WHEN_FILE_SIZE_REACHES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-new_log_file_frequency).

### `PROPERTY_ACCOUNTING_LOG_FILE_DIRECTORY`

The file-system path to the directory where the log file is located. This path does not include the filename. It also does not include a trailing backslash.

### `PROPERTY_ACCOUNTING_LOG_IAS1_FORMAT`

Specifies whether the log should be in NPS format or database convertible format. This property can have the following values.

| Value | Meaning |
| --- | --- |
| 0 (**VARIANT_FALSE**) | NPS Format |
| 0xFFFF (**VARIANT_TRUE**) | Database Convertible Format |

### `PROPERTY_ACCOUNTING_LOG_ENABLE_LOGGING`

Not used.

### `PROPERTY_ACCOUNTING_LOG_DELETE_IF_FULL`

Causes the accounting log to be deleted when full.

### `PROPERTY_ACCOUNTING_SQL_MAX_SESSIONS`

Maximum number of concurrent SQL server sessions.

### `PROPERTY_ACCOUNTING_LOG_AUTHENTICATION_INTERIM`

Causes NPS to log interim access-request/access-challenge pairs for an EAP session. Otherwise, it only logs the final access-request/access-accept/reject.

### `PROPERTY_ACCOUNTING_LOG_FILE_IS_BACKUP`

### `PROPERTY_ACCOUNTING_DISCARD_REQUEST_ON_FAILURE`

#### - PROPERTY_ACCOUNTING_LOG_ENABLE

Not used.

## See also

[Automation Types](https://learn.microsoft.com/previous-versions/windows/desktop/automat/oleautomation)

[NEW_LOG_FILE_FREQUENCY](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-new_log_file_frequency)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)