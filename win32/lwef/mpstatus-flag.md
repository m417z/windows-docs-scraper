# MPSTATUS\_FLAG enumeration

Possible overall product status bit flags.

## Constants

**MP\_STATUS\_FLAG\_NONE**

No status flags set (non-initialized state).

**MP\_STATUS\_FLAG\_SERVICE\_UNAVAILABLE**

Service not running.

**MP\_STATUS\_FLAG\_MPENGINE\_UNAVAILABLE**

Service started without any malware protection engine.

**MP\_STATUS\_FLAG\_THREAT\_FULLSCAN\_REQUIRED**

Pending full scan due to threat action.

**MP\_STATUS\_FLAG\_THREAT\_REBOOT\_REQUIRED**

Pending reboot due to threat action.

**MP\_STATUS\_FLAG\_THREAT\_MANUAL\_STEPS\_REQUIRED**

Pending manual steps due to threat action.

**MP\_STATUS\_FLAG\_DUE\_AV\_SIGNATURE**

Antivirus signatures out of date.

**MP\_STATUS\_FLAG\_DUE\_AS\_SIGNATURE**

Antispyware signatures out of date.

**MP\_STATUS\_FLAG\_DUE\_QUICK\_SCAN**

No quick scan has happened for a specified period.

**MP\_STATUS\_FLAG\_DUE\_FULL\_SCAN**

no full scan has happened for a specified period

**MP\_STATUS\_FLAG\_INPROGRESS\_SYSTEM\_SCAN**

System-initiated scan in progress.

**MP\_STATUS\_FLAG\_INPROGRESS\_ROUTINE\_CLEANING**

System-initiated clean in progress.

**MP\_STATUS\_FLAG\_DUE\_SAMPLES**

There are samples pending submission.

**MP\_STATUS\_FLAG\_EVALUATION\_MODE**

Product is running in evaluation mode.

**MP\_STATUS\_FLAG\_NONGENUINE**

Product is running in non-genuine Windows mode.

**MP\_STATUS\_FLAG\_PRODUCT\_EXPIRED**

Product expired.

**MP\_STATUS\_FLAG\_THREAT\_CALLISTO\_REQUIRED**

Callisto off-line scan required.

**MP\_STATUS\_FLAG\_SERVICE\_ON\_SYSTEM\_SHUTDOWN**

Service is shutting down as part of system shutdown.

**MP\_STATUS\_FLAG\_SERVICE\_CRITICAL\_FAILURE**

Threat remediation failed critically.

**MP\_STATUS\_FLAG\_SERVICE\_NON\_CRITICAL\_FAILURE**

Threat remediation failed non-critically.

**MP\_STATUS\_FLAG\_HEALTH\_INITIALIZED**

No status flags set (well-initialized state).

**MP\_STATUS\_FLAG\_DUE\_PLATFORM\_UPDATE**

The platform is out of date.

**MP\_STATUS\_FLAG\_INPROGRESS\_PLATFORM\_UPDATE**

Platform update is in progress.

**MP\_STATUS\_FLAG\_PLATFORM\_ABOUT\_TO\_BE\_OUTDATED**

The platform is about to be outdated

**MP\_STATUS\_FLAG\_END\_OF\_LIFE**

The signature or platform end of life is past or is pending.

**MP\_STATUS\_FLAG\_MAX**

Maximum valid flag.

**MP\_STATUS\_FLAG\_ALL**

Maximum value possible.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

