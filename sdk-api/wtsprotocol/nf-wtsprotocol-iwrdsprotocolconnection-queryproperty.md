# IWRdsProtocolConnection::QueryProperty

## Description

Retrieves a property value from the protocol. This method can be used by other Windows modules to request data from or send data to the protocol.

## Parameters

### `QueryType` [in]

A **GUID** that specifies the requested property. This can be one of the following values.

#### WRDS_QUERY_ALLOWED_INITIAL_APP (C77D1B30-5BE1-4c6b-A0E1-BD6D2E5C9FCC)

Sent by the Remote Desktop Services service to determine whether an initial application should be permitted to run.

On input, the Remote Desktop Services service passes three [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures in the *pPropertyEntriesIn* parameter:

Input structure 1:

* `pPropertyEntriesIn[0].Type =` **WRDS_VALUE_TYPE_STRING**
* `pPropertyEntriesIn[0].u.strVal.pstrVal =` *application name*
* `pPropertyEntriesIn[0].u.strVal.size =` *length of the name string*

Input structure 2:

* `pPropertyEntriesIn[1].Type =` **WRDS_VALUE_TYPE_STRING**
* `pPropertyEntriesIn[1].u.strVal.pstrVal =` *application parameters*
* `pPropertyEntriesIn[1].u.strVal.size =` *length of the parameter string*

Input structure 3:

* `pPropertyEntriesIn[2].Type =` **WRDS_VALUE_TYPE_ULONG**
* `pPropertyEntriesIn[2].u.ulVal =` *Reserved*

On output, pass the following three [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures in the *pPropertyEntriesOut* parameter. If you want to use the application passed in by the Remote Desktop Services service , copy input structures 1 and 2 to output structures 1 and 2.

Output structure 1:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_STRING**
* `pPropertyEntriesOut[0].u.strVal.pstrVal =` *command line including the directory*
* `pPropertyEntriesOut[0].u.strVal.size =` *length of command line*

Output structure 2:

* `pPropertyEntriesOut[1].Type =` **WRDS_VALUE_TYPE_STRING**
* `pPropertyEntriesOut[1].u.strVal.pstrVal =` *application parameters*
* `pPropertyEntriesOut[1].u.strVal.size =` *length of the parameter string*

Output structure 3:

* `pPropertyEntriesOut[2].Type =` **WRDS_VALUE_TYPE_ULONG**
* `pPropertyEntriesOut[2].u.ulVal =` *Any value other than zero to run the application, zero to stop*

#### WRDS_QUERY_LOGON_SCREEN_SIZE (8b8e0fe7-0804-4a0e-b279-8660b1df0049)

Used by WinLogon to determine the size of the logon screen.

The *pPropertyEntriesIn* parameter will be **NULL**.

Set the *pPropertyEntriesOut* parameter to the following:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_ULONG**
* `pPropertyEntriesOut[0].u.ulVal =` *screen size*

If you do not want to use the default screen size, the protocol must return **E_NOTIMPL**.

#### WRDS_QUERY_AUDIOENUM_DLL (9bf4fa97-c883-4c2a-80ab-5a39c9af00db)

Used by the Remote Desktop Services service to query for the name of the remote audio enumerator DLL.

The *pPropertyEntriesIn* parameter will be **NULL**.

Set the *pPropertyEntriesOut* parameter to the following:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_STRING**
* `pPropertyEntriesOut[0].u.strVal.pstrVal =` *DLL name*

You must allocate the memory for **pstrVal** by using the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function.

#### WRDS_QUERY_MF_FORMAT_SUPPORT (41869ad0-6332-4dc8-95d5-db749e2f1d94)

Used by the Remote Desktop Media Foundation plug-in to determine the sink objects to be used for specific media formats.

On input, the RCM passes the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesIn* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_BINARY**
* `pPropertyEntriesOut[0].u.bVal.pbVal =` [TSMF_SUPPORT_DATA_IN](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-in) structure
* `pPropertyEntriesOut[0].u.bVal.size =` size of [TSMF_SUPPORT_DATA_IN](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-in) structure

On output, pass the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesOut* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_BINARY**
* `pPropertyEntriesOut[0].u.bVal.pbVal =` [TSMF_SUPPORT_DATA_OUT](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-out) structure
* `pPropertyEntriesOut[0].u.bVal.size =` Size of [TSMF_SUPPORT_DATA_OUT](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-out) structure

#### PROPERTY_DYNAMIC_TIME_ZONE_INFORMATION (cdfd28e-d0b9-4c1f-a5eb-6d1f6c6535b9)

Used to retrieve the dynamic time zone information from a connection.

The *pPropertyEntriesIn* parameter will be **NULL**.

On output, pass the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesOut* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_BINARY**
* `pPropertyEntriesOut[0].u.bVal.pbVal =` [WRDS_DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_dynamic_time_zone_information) structure
* `pPropertyEntriesOut[0].u.bVal.size =` Size of [WRDS_DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_dynamic_time_zone_information) structure

#### CONNECTION_PROPERTY_CURSOR_BLINK_DISABLED (4b150580-fea4-4d3c-9de4-7433a66618f7)

Used to determine whether cursor blink should be disabled.

The *pPropertyEntriesIn* parameter will be **NULL**.

On output, pass the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesOut* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_ULONG**
* `pPropertyEntriesOut[0].u.ulVal =` *1 to disable cursor blink, 0 otherwise*

#### PROPERTY_TYPE_GET_FAST_RECONNECT (6212d757-0043-4862-99c3-9f3059ac2a3b)

Used by the Remote Desktop Services service to determine the mode of reconnection to be used.

The *pPropertyEntriesIn* parameter will be **NULL**.

On output, pass the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesOut* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_ULONG**
* `pPropertyEntriesOut[0].u.ulVal =` *0 to disable fast reconnect, 1 for Basic Fast Reconnect, 2 for Enhanced Fast Reconnect*

#### PROPERTY_TYPE_GET_FAST_RECONNECT_USER_SID (197c427a-0135-4b6d-9c5e-e6579a0ab625)

Used by the Remote Desktop Services service during Enhanced Fast Reconnect to retrieve the User SID by which sessions to be reconnected to are filtered.

The *pPropertyEntriesIn* parameter will be **NULL**.

On output, pass the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesOut* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_STRING**
* `pPropertyEntriesIn[0].u.strVal.pstrVal =` *User SID to be used as session filter*
* `pPropertyEntriesIn[0].u.strVal.size =` *Length of User SID including the null terminating character*

You must allocate the memory for **pstrVal** by using the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function.

#### PROPERTY_TYPE_ENABLE_UNIVERSAL_APPS_FOR_CUSTOM_SHELL (ed2c3fda-338d-4d3f-81a3-e767310d908e)

Used by the Remote Desktop Services service determine if ShellAppRuntime.exe will be launched before any Custom Shells during session creation. ShellAppRuntime.exe implements Universal App support for Custom Shells. This is not enabled by default (equivalent to passing zero). This is available in Windows versions that are Server 2019 and above or Windows 10 multi-session Build 18950 and above.

The *pPropertyEntriesIn* parameter will be **NULL**.

On output, pass the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesOut* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_ULONG**
* `pPropertyEntriesOut[0].u.ulVal =` *0 to not enable Universal Apps Support for Custom Shells, 1 Enable Universal Apps Support for Custom Shells*

#### CONNECTION_PROPERTY_IDLE_TIME_WARNING (693f7ff5-0c4e-4d17-b8e0-1f70325e5d58)

Used to determine whether a logoff warning prompt is displayed when the idle timer expires.

The *pPropertyEntriesIn* parameter will be **NULL**.

On output, pass the following [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the *pPropertyEntriesOut* parameter:

* `pPropertyEntriesOut[0].Type =` **WRDS_VALUE_TYPE_ULONG**
* `pPropertyEntriesOut[0].u.ulVal =` *0 to disable warning prompt, 1 to enable it*

### `ulNumEntriesIn` [in]

The number of entries in the *pPropertyEntriesIn* array.

### `ulNumEntriesOut` [in]

The number of entries in the *pPropertyEntriesOut* array.

### `pPropertyEntriesIn` [in, optional]

An array of pointers to [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures that can be used to help find the requested property information.

### `pPropertyEntriesOut` [out, optional]

An array of pointers to [WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures that receive the requested property values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)