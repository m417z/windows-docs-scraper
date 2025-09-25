# IOCSPAdmin::get_OCSPServiceProperties

## Description

The **OCSPServiceProperties** property gets an instance of an [OCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection) object. This object represents the attributes of an Online Certificate Status Protocol (OCSP) responder service. After instantiating an [OCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin) object, a script or administration tool can use the retrieved [IOCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection) interface to expose responder-service attributes.

This property is read-only.

## Parameters

## Remarks

The following table lists the possible [Name](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_name)-[Value](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_value) pairs for OCSP service properties.

| Name | Value |
| --- | --- |
| **LogLevel** | The [Value](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_value) of **LogLevel** must be one of the following constants.<br><br>Constant: CERTLOG_MINIMAL<br><br>**DWORD**: 0<br><br>Constant: CERTLOG_TERSE<br><br>**DWORD**: 1<br><br>Constant: CERTLOG_ERROR<br><br>**DWORD**: 2<br><br>Constant: CERTLOG_WARNING<br><br>**DWORD**: 3 (default)<br><br>Constant: CERTLOG_VERBOSE<br><br>**DWORD**: 4<br><br>Constant: CERTLOG_EXHAUSTIVE<br><br>**DWORD**: 5 |
| **AuditFilter** | The [Value](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_value) of **AuditFilter** can be any bitwise combination of the following **DWORD** values.<br><br>Description: Audit OCSP service start/stop<br><br>**DWORD**: 0x1<br><br>Description: Changes to the OCSP configuration<br><br>**DWORD**: 0x2<br><br>Description: Requests submitted to the OCSP<br><br>**DWORD**: 0x4<br><br>Description: Changes to the OCSP security settings<br><br>**DWORD**: 0x8 |
| **ArrayController** | The [Value](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_value) of **ArrayController** must be a string that represents the computer name of the OCSP server that acts as the array controller for an OCSP array configuration. |
| **ArrayMembers** | The [Value](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_value) of **ArrayMembers** can be a multiple-line string that represents the computer names of the OCSP servers that are part of an OCSP array configuration. |
| **EnrollPollInterval** | The [Value](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_value) of **EnrollPollInterval** must be a **DWORD** value from 0 to 24 that represents the number of hours between OCSP service certificate enrollment attempts. This interval determines how often the service checks the status of target certificates for a template change or pending validity change. When the service finds a change, it attempts to enroll for a new certificate. |

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)