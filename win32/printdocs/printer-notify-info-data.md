# PRINTER\_NOTIFY\_INFO\_DATA structure

The **PRINTER\_NOTIFY\_INFO\_DATA** structure identifies a job or printer information field and provides the current data for that field.

The [**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification) function returns a [**PRINTER\_NOTIFY\_INFO**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info) structure, which contains an array of **PRINTER\_NOTIFY\_INFO\_DATA** structures.

## Members

**Type**

Indicates the type of information provided. This member can be one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
|

**JOB\_NOTIFY\_TYPE**

0x01

| Indicates that the **Field** member specifies a JOB\_NOTIFY\_FIELD\_\* constant.<br> |
|

**PRINTER\_NOTIFY\_TYPE**

0x00

| Indicates that the **Field** member specifies a PRINTER\_NOTIFY\_FIELD\_\* constant.<br> |

**Field**

Indicates the field that changed. For a list of possible values, see the Remarks section.

**Reserved**

Reserved.

**Id**

Indicates the job identifier if the **Type** member specifies JOB\_NOTIFY\_TYPE. If the **Type** member specifies PRINTER\_NOTIFY\_TYPE, this member is undefined.

**NotifyData**

A union of data information based on the **Type** and **Field** members. For a description of the type of data associated with each field, see the Remarks section.

**adwData\[2\]**

An array of two **DWORD** values. For information fields that use only a single **DWORD**, the data is in **adwData** \[0\].

**Data**

**cbBuf**

Indicates the size, in bytes, of the buffer pointed to by **pBuf**.

**pBuf**

Pointer to a buffer that contains the field's current data.

## Remarks

If the **Type** member specifies PRINTER\_NOTIFY\_TYPE, the **Field** member can be one of the following values.

| Field | Type of data | Value |
| --- | --- | --- |
| PRINTER_NOTIFY_FIELD_SERVER_NAME | Not supported. | 0x00 |
| PRINTER_NOTIFY_FIELD_PRINTER_NAME | **pBuf** is a pointer to a null-terminated string containing the name of the printer. | 0x01 |
| PRINTER_NOTIFY_FIELD_SHARE_NAME | **pBuf** is a pointer to a null-terminated string that identifies the share point for the printer. | 0x02 |
| PRINTER_NOTIFY_FIELD_PORT_NAME | **pBuf** is a pointer to a null-terminated string containing the name of the port that the print jobs will be printed to. If "Printer Pooling" is selected, this is a comma separated list of ports. | 0x03 |
| PRINTER_NOTIFY_FIELD_DRIVER_NAME | **pBuf** is a pointer to a null-terminated string containing the name of the printer's driver. | 0x04 |
| PRINTER_NOTIFY_FIELD_COMMENT | **pBuf** is a pointer to a null-terminated string containing the new comment string, which is typically a brief description of the printer. | 0x05 |
| PRINTER_NOTIFY_FIELD_LOCATION | **pBuf** is a pointer to a null-terminated string containing the new physical location of the printer (for example, "Bldg. 38, Room 1164"). | 0x06 |
| PRINTER_NOTIFY_FIELD_DEVMODE | **pBuf** is a pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that defines default printer data such as the paper orientation and the resolution. | 0x07 |
| PRINTER_NOTIFY_FIELD_SEPFILE | **pBuf** is a pointer to a null-terminated string that specifies the name of the file used to create the separator page. This page is used to separate print jobs sent to the printer. | 0x08 |
| PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR | **pBuf** is a pointer to a null-terminated string that specifies the name of the print processor used by the printer. | 0x09 |
| PRINTER_NOTIFY_FIELD_PARAMETERS | **pBuf** is a pointer to a null-terminated string that specifies the default print-processor parameters. | 0x0A |
| PRINTER_NOTIFY_FIELD_DATATYPE | **pBuf** is a pointer to a null-terminated string that specifies the data type used to record the print job. | 0x0B |
| PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR | **pBuf** is a pointer to a [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure for the printer. The pointer may be **NULL** if there is no security descriptor. | 0x0C |
| PRINTER_NOTIFY_FIELD_ATTRIBUTES | **adwData** [0] specifies the printer attributes, which can be one of the following values:<br><br>PRINTER_ATTRIBUTE_QUEUED\ PRINTER_ATTRIBUTE_DIRECT\ PRINTER_ATTRIBUTE_DEFAULT\ PRINTER_ATTRIBUTE_SHARED\ | 0x0D |
| PRINTER_NOTIFY_FIELD_PRIORITY | **adwData** [0] specifies a priority value that the spooler uses to route print jobs. | 0x0E |
| PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY | **adwData** [0] specifies the default priority value assigned to each print job. | 0x0F |
| PRINTER_NOTIFY_FIELD_START_TIME | **adwData** [0] specifies the earliest time at which the printer will print a job. (This value is specified in minutes elapsed since 12:00 A.M.) | 0x10 |
| PRINTER_NOTIFY_FIELD_UNTIL_TIME | **adwData** [0] specifies the latest time at which the printer will print a job. (This value is specified in minutes elapsed since 12:00 A.M.) | 0x11 |
| PRINTER_NOTIFY_FIELD_STATUS | **adwData** [0] specifies the printer status. For a list of possible values, see the [**PRINTER_INFO_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure. | 0x12 |
| PRINTER_NOTIFY_FIELD_STATUS_STRING | Not supported. | 0x13 |
| PRINTER_NOTIFY_FIELD_CJOBS | **adwData** [0] specifies the number of print jobs that have been queued for the printer. | 0x14 |
| PRINTER_NOTIFY_FIELD_AVERAGE_PPM | **adwData** [0] specifies the average number of pages per minute that have been printed on the printer. | 0x15 |
| PRINTER_NOTIFY_FIELD_TOTAL_PAGES | Not supported. | 0x16 |
| PRINTER_NOTIFY_FIELD_PAGES_PRINTED | Not supported. | 0x17 |
| PRINTER_NOTIFY_FIELD_TOTAL_BYTES | Not supported. | 0x18 |
| PRINTER_NOTIFY_FIELD_BYTES_PRINTED | Not supported. | 0x19 |
| PRINTER_NOTIFY_FIELD_OBJECT_GUID | This is set if the object GUID changes. | 0x1A |
| PRINTER_NOTIFY_FIELD_FRIENDLY_NAME | This is set if the printer connection is renamed. | 0x1B |

If the **Type** member specifies JOB\_NOTIFY\_TYPE, the **Field** member can be one of the following values.

| Field | Type of data | Value |
|------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------|
| JOB\_NOTIFY\_FIELD\_PRINTER\_NAME | **pBuf** is a pointer to a null-terminated string containing the name of the printer for which the job is spooled. | 0x00 |
| JOB\_NOTIFY\_FIELD\_MACHINE\_NAME | **pBuf** is a pointer to a null-terminated string that specifies the name of the machine that created the print job. | 0x01 |
| JOB\_NOTIFY\_FIELD\_PORT\_NAME | **pBuf** is a pointer to a null-terminated string that identifies the port(s) used to transmit data to the printer. If a printer is connected to more than one port, the names of the ports are separated by commas (for example, "LPT1:,LPT2:,LPT3:"). | 0x02 |
| JOB\_NOTIFY\_FIELD\_USER\_NAME | **pBuf** is a pointer to a null-terminated string that specifies the name of the user who sent the print job. | 0x03 |
| JOB\_NOTIFY\_FIELD\_NOTIFY\_NAME | **pBuf** is a pointer to a null-terminated string that specifies the name of the user who should be notified when the job has been printed or when an error occurs while printing the job. | 0x04 |
| JOB\_NOTIFY\_FIELD\_DATATYPE | **pBuf** is a pointer to a null-terminated string that specifies the type of data used to record the print job. | 0x05 |
| JOB\_NOTIFY\_FIELD\_PRINT\_PROCESSOR | **pBuf** is a pointer to a null-terminated string that specifies the name of the print processor to be used to print the job. | 0x06 |
| JOB\_NOTIFY\_FIELD\_PARAMETERS | **pBuf** is a pointer to a null-terminated string that specifies print-processor parameters. | 0x07 |
| JOB\_NOTIFY\_FIELD\_DRIVER\_NAME | **pBuf** is a pointer to a null-terminated string that specifies the name of the printer driver that should be used to process the print job. | 0x08 |
| JOB\_NOTIFY\_FIELD\_DEVMODE | **pBuf** is a pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that contains device-initialization and environment data for the printer driver. | 0x09 |
| JOB\_NOTIFY\_FIELD\_STATUS | **adwData** \[0\] specifies the job status. For a list of possible values, see the [**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2) structure. | 0x0A |
| JOB\_NOTIFY\_FIELD\_STATUS\_STRING | **pBuf** is a pointer to a null-terminated string that specifies the status of the print job. | 0x0B |
| JOB\_NOTIFY\_FIELD\_SECURITY\_DESCRIPTOR | Not supported. | 0x0C |
| JOB\_NOTIFY\_FIELD\_DOCUMENT | **pBuf** is a pointer to a null-terminated string that specifies the name of the print job (for example, "MS-WORD: Review.doc"). | 0x0D |
| JOB\_NOTIFY\_FIELD\_PRIORITY | **adwData** \[0\] specifies the job priority. | 0x0E |
| JOB\_NOTIFY\_FIELD\_POSITION | **adwData** \[0\] specifies the job's position in the print queue. | 0x0F |
| JOB\_NOTIFY\_FIELD\_SUBMITTED | **pBuf** is a pointer to a [**SYSTEMTIME**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the time when the job was submitted. | 0x10 |
| JOB\_NOTIFY\_FIELD\_START\_TIME | **adwData** \[0\] specifies the earliest time that the job can be printed. (This value is specified in minutes elapsed since 12:00 A.M.) | 0x11 |
| JOB\_NOTIFY\_FIELD\_UNTIL\_TIME | **adwData** \[0\] specifies the latest time that the job can be printed. (This value is specified in minutes elapsed since 12:00 A.M.) | 0x12 |
| JOB\_NOTIFY\_FIELD\_TIME | **adwData** \[0\] specifies the total time, in seconds, that has elapsed since the job began printing. | 0x13 |
| JOB\_NOTIFY\_FIELD\_TOTAL\_PAGES | **adwData** \[0\] specifies the size, in pages, of the job. | 0x14 |
| JOB\_NOTIFY\_FIELD\_PAGES\_PRINTED | **adwData** \[0\] specifies the number of pages that have printed. | 0x15 |
| JOB\_NOTIFY\_FIELD\_TOTAL\_BYTES | **adwData** \[0\] specifies the size, in bytes, of the job. | 0x16 |
| JOB\_NOTIFY\_FIELD\_BYTES\_PRINTED | **adwData** \[0\] specifies the number of bytes that have been printed on this job. For this field, the change notification object is signaled when bytes are sent to the printer. | 0x17 |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[**FindNextPrinterChangeNotification**](https://learn.microsoft.com/windows/win32/printdocs/findnextprinterchangenotification)

[**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_NOTIFY\_INFO**](https://learn.microsoft.com/windows/win32/printdocs/printer-notify-info)

[**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[**SYSTEMTIME**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)