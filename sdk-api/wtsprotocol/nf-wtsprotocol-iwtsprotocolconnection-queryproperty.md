# IWTSProtocolConnection::QueryProperty

## Description

[**IWTSProtocolConnection::QueryProperty**
is no longer available for use as of Windows Server 2012. Instead, use
[IWRdsProtocolConnection::QueryProperty](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-queryproperty).]

Retrieves the specified property from the protocol. This method can be used by other Windows
modules to request data from or send data to the protocol.

## Parameters

### `QueryType` [in]

A **GUID** that specifies the property. This can be one of the following values.

#### WTS_QUERY_ALLOWED_INITIAL_APP (C77D1B30-5BE1-4c6b-A0E1-BD6D2E5C9FCC)

Sent by the Remote Desktop Services service to determine whether an initial application should be
permitted to run.

On input, the Remote Desktop Services service passes three
[WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures in the
*pPropertyEntriesIn* parameter:

Input structure 1:

* pPropertyEntriesIn[0].Type = **WTS_VALUE_TYPE_STRING**
* pPropertyEntriesIn[0].u.strVal.pstrVal = *application name*
* pPropertyEntriesIn[0].u.strVal.size = *length of the name string*

Input structure 2:

* pPropertyEntriesIn[1].Type = **WTS_VALUE_TYPE_STRING**
* pPropertyEntriesIn[1].u.strVal.pstrVal = *application parameters*
* pPropertyEntriesIn[1].u.strVal.size = *length of the parameter string*

Input structure 3:

* pPropertyEntriesIn[2].Type = **WTS_VALUE_TYPE_ULONG**
* pPropertyEntriesIn[2].u.ulVal = *reserved*

On output, pass the following three
[WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures in the
*pPropertyEntriesOut* parameter. If you want to use the application passed in by the
Remote Desktop Services service , copy input structures 1 and 2 to output structures 1 and 2.

Output structure 1:

* pPropertyEntriesOut[0].Type = **WTS_VALUE_TYPE_STRING**
* pPropertyEntriesOut[0].u.strVal.pstrVal = *command line including the directory*
* pPropertyEntriesOut[0].u.strVal.size = *length of command line*

Output structure 2:

* pPropertyEntriesOut[1].Type = **WTS_VALUE_TYPE_STRING**
* pPropertyEntriesOut[1].u.strVal.pstrVal = *application parameters*
* pPropertyEntriesOut[1].u.strVal.size = *length of the parameter string*

Output structure 3:

* pPropertyEntriesOut[2].Type = **WTS_VALUE_TYPE_ULONG**
* pPropertyEntriesOut[2].u.ulVal = *Any value other than zero to run the application, zero to stop*

#### WTS_QUERY_LOGON_SCREEN_SIZE (8b8e0fe7-0804-4a0e-b279-8660b1df0049)

Used by WinLogon to determine the size of the logon screen.

The *pPropertyEntriesIn* parameter will be
**NULL**.

Set the *pPropertyEntriesOut* parameter to the following:

* pPropertyEntriesOut[0].Type = **WTS_VALUE_TYPE_ULONG**
* pPropertyEntriesOut[0].u.ulVal = *screen size*

If you do not want to use the default screen size, the protocol must return
**E_NOTIMPL**.

#### WTS_QUERY_AUDIOENUM_DLL (9bf4fa97-c883-4c2a-80ab-5a39c9af00db)

Used by the Remote Desktop Services service to query for the name of the remote audio enumerator DLL.

The *pPropertyEntriesIn* parameter will be
**NULL**.

Set the *pPropertyEntriesOut* parameter to the following :

* pPropertyEntriesOut[0].Type = **WTS_VALUE_TYPE_STRING**
* pPropertyEntriesOut[0].u.strVal.pstrVal = *DLL name*

You must allocate the memory for **pstrVal** by using the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function.

#### WTS_QUERY_MF_FORMAT_SUPPORT (41869ad0-6332-4dc8-95d5-db749e2f1d94)

Used by the Remote Desktop Media Foundation plug-in to determine the sink objects to be used for specific
media formats.

On input, the RCM passes the following
[WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the
*pPropertyEntriesIn* parameter:

* pPropertyEntriesOut[0].Type = **WTS_VALUE_TYPE_BINARY**
* pPropertyEntriesOut[0].u.bVal.pbVal = [TSMF_SUPPORT_DATA_IN](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-in)
* pPropertyEntriesOut[0].u.bVal.size = Size of [TSMF_SUPPORT_DATA_IN](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-in)

On output, pass the following
[WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the
*pPropertyEntriesOut* parameter.

* pPropertyEntriesOut[0].Type = **WTS_VALUE_TYPE_BINARY**
* pPropertyEntriesOut[0].u.bVal.pbVal = [TSMF_SUPPORT_DATA_OUT](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-out)
* pPropertyEntriesOut[0].u.bVal.size = Size of [TSMF_SUPPORT_DATA_OUT](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-out)

#### PROPERTY_DYNAMIC_TIME_ZONE_INFORMATION (cdfd28e-d0b9-4c1f-a5eb-6d1f6c6535b9)

Used to retrieve the dynamic time zone information from a connection.

The *pPropertyEntriesIn* parameter will be
**NULL**.

On output, pass the following
[WRDS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structure in the
*pPropertyEntriesOut* parameter:

* pPropertyEntriesOut[0].Type = **WRDS_VALUE_TYPE_BINARY**
* pPropertyEntriesOut[0].u.bVal.pbVal = [WRDS_DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_dynamic_time_zone_information) structure
* pPropertyEntriesOut[0].u.bVal.size = Size of [WRDS_DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_dynamic_time_zone_information) structure

### `ulNumEntriesIn` [in]

An integer that contains the number of
[WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures passed in the
*pPropertyEntriesIn* argument.

### `ulNumEntriesOut` [in]

An integer that contains the number of
[WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures passed in the
*pPropertyEntriesOut* argument.

### `pPropertyEntriesIn` [in, optional]

One or more [WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures
that can be used to help find the requested property information.

### `pPropertyEntriesOut` [out, optional]

One or more [WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value) structures
that contain the requested property information.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)

[IWRdsProtocolConnection::QueryProperty](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-queryproperty)

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)

[TSMF_SUPPORT_DATA_IN](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-in)

[TSMF_SUPPORT_DATA_OUT](https://learn.microsoft.com/windows/desktop/TermServ/tsmf-support-data-out)

[WRDS_DYNAMIC_TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_dynamic_time_zone_information)

[WTS_PROPERTY_VALUE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_property_value)