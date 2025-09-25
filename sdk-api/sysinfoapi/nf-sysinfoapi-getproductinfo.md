# GetProductInfo function

## Description

Retrieves the product type for the operating system on the local computer, and maps the type to the product types supported by the specified operating system.

To retrieve product type information on versions of Windows prior to the minimum supported operating systems specified in the Requirements section, use the [GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa) function. You can also use the **OperatingSystemSKU** property of the [Win32_OperatingSystem](https://learn.microsoft.com/windows/desktop/CIMWin32Prov/win32-operatingsystem) WMI class.

## Parameters

### `dwOSMajorVersion` [in]

The major version number of the operating system. The minimum value is 6.

The combination of the *dwOSMajorVersion*, *dwOSMinorVersion*, *dwSpMajorVersion*, and *dwSpMinorVersion* parameters describes the maximum target operating system version for the application. For example, Windows Vista and Windows Server 2008 are version 6.0.0.0 and Windows 7 and Windows Server 2008 R2 are version 6.1.0.0. All Windows 10 based releases will be listed as version 6.3.

### `dwOSMinorVersion` [in]

The minor version number of the operating system. The minimum value is 0.

### `dwSpMajorVersion` [in]

The major version number of the operating system service pack. The minimum value is 0.

### `dwSpMinorVersion` [in]

The minor version number of the operating system service pack. The minimum value is 0.

### `pdwReturnedProductType` [out]

The product type. This parameter cannot be **NULL**. If the specified operating system is less than the current operating system, this information is mapped to the types supported by the specified operating system. If the specified operating system is greater than the highest supported operating system, this information is mapped to the types supported by the current operating system.

 This parameter can be one of the following values (some products below may be out of support).

| Value | Meaning |
| --- | --- |
| **PRODUCT_BUSINESS**<br><br>0x00000006 | Business |
| **PRODUCT_BUSINESS_N**<br><br>0x00000010 | Business N |
| **PRODUCT_CLUSTER_SERVER**<br><br>0x00000012 | HPC Edition |
| **PRODUCT_CLUSTER_SERVER_V**<br><br>0x00000040 | Server Hyper Core V |
| **PRODUCT_CORE**<br><br>0x00000065 | Windows 10 Home |
| **PRODUCT_CORE_COUNTRYSPECIFIC**<br><br>0x00000063 | Windows 10 Home China |
| **PRODUCT_CORE_N**<br><br>0x00000062 | Windows 10 Home N |
| **PRODUCT_CORE_SINGLELANGUAGE**<br><br>0x00000064 | Windows 10 Home Single Language |
| **PRODUCT_DATACENTER_EVALUATION_SERVER**<br><br>0x00000050 | Server Datacenter (evaluation installation) |
| **PRODUCT_DATACENTER_A_SERVER_CORE**<br><br>0x00000091 | Server Datacenter, Semi-Annual Channel (core installation) |
| **PRODUCT_STANDARD_A_SERVER_CORE**<br><br>0x00000092 | Server Standard, Semi-Annual Channel (core installation) |
| **PRODUCT_DATACENTER_SERVER**<br><br>0x00000008 | Server Datacenter (full installation. For Server Core installations of Windows Server 2012 and later, use the method, [Determining whether Server Core is running](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh846315(v=vs.85)).) |
| **PRODUCT_DATACENTER_SERVER_CORE**<br><br>0x0000000C | Server Datacenter (core installation, Windows Server 2008 R2 and earlier) |
| **PRODUCT_DATACENTER_SERVER_CORE_V**<br><br>0x00000027 | Server Datacenter without Hyper-V (core installation) |
| **PRODUCT_DATACENTER_SERVER_V**<br><br>0x00000025 | Server Datacenter without Hyper-V (full installation) |
| **PRODUCT_EDUCATION**<br><br>0x00000079 | Windows 10 Education |
| **PRODUCT_EDUCATION_N**<br><br>0x0000007A | Windows 10 Education N |
| **PRODUCT_ENTERPRISE**<br><br>0x00000004 | Windows 10 Enterprise |
| **PRODUCT_ENTERPRISE_E**<br><br>0x00000046 | Windows 10 Enterprise E |
| **PRODUCT_ENTERPRISE_EVALUATION**<br><br>0x00000048 | Windows 10 Enterprise Evaluation |
| **PRODUCT_ENTERPRISE_N**<br><br>0x0000001B | Windows 10 Enterprise N |
| **PRODUCT_ENTERPRISE_N_EVALUATION**<br><br>0x00000054 | Windows 10 Enterprise N Evaluation |
| **PRODUCT_ENTERPRISE_S**<br><br>0x0000007D | Windows 10 Enterprise 2015 LTSB |
| **PRODUCT_ENTERPRISE_S_EVALUATION**<br><br>0x00000081 | Windows 10 Enterprise 2015 LTSB Evaluation |
| **PRODUCT_ENTERPRISE_S_N**<br><br>0x0000007E | Windows 10 Enterprise 2015 LTSB N |
| **PRODUCT_ENTERPRISE_S_N_EVALUATION**<br><br>0x00000082 | Windows 10 Enterprise 2015 LTSB N Evaluation |
| **PRODUCT_ENTERPRISE_SERVER**<br><br>0x0000000A | Server Enterprise (full installation) |
| **PRODUCT_ENTERPRISE_SERVER_CORE**<br><br>0x0000000E | Server Enterprise (core installation) |
| **PRODUCT_ENTERPRISE_SERVER_CORE_V**<br><br>0x00000029 | Server Enterprise without Hyper-V (core installation) |
| **PRODUCT_ENTERPRISE_SERVER_IA64**<br><br>0x0000000F | Server Enterprise for Itanium-based Systems |
| **PRODUCT_ENTERPRISE_SERVER_V**<br><br>0x00000026 | Server Enterprise without Hyper-V (full installation) |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL**<br><br>0x0000003C | Windows Essential Server Solution Additional |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC**<br><br>0x0000003E | Windows Essential Server Solution Additional SVC |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT**<br><br>0x0000003B | Windows Essential Server Solution Management |
| **PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC**<br><br>0x0000003D | Windows Essential Server Solution Management SVC |
| **PRODUCT_HOME_BASIC**<br><br>0x00000002 | Home Basic |
| **PRODUCT_HOME_BASIC_E**<br><br>0x00000043 | Not supported |
| **PRODUCT_HOME_BASIC_N**<br><br>0x00000005 | Home Basic N |
| **PRODUCT_HOME_PREMIUM**<br><br>0x00000003 | Home Premium |
| **PRODUCT_HOME_PREMIUM_E**<br><br>0x00000044 | Not supported |
| **PRODUCT_HOME_PREMIUM_N**<br><br>0x0000001A | Home Premium N |
| **PRODUCT_HOME_PREMIUM_SERVER**<br><br>0x00000022 | Windows Home Server 2011 |
| **PRODUCT_HOME_SERVER**<br><br>0x00000013 | Windows Storage Server 2008 R2 Essentials |
| **PRODUCT_HYPERV**<br><br>0x0000002A | Microsoft Hyper-V Server |
| **PRODUCT_IOTENTERPRISE**<br><br>0x000000BC | Windows IoT Enterprise |
| **PRODUCT_IOTENTERPRISE_S**<br><br>0x000000BF | Windows IoT Enterprise LTSC |
| **PRODUCT_IOTUAP**<br><br>0x0000007B | Windows 10 IoT Core |
| **PRODUCT_IOTUAPCOMMERCIAL**<br><br>0x00000083 | Windows 10 IoT Core Commercial |
| **PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT**<br><br>0x0000001E | Windows Essential Business Server Management Server |
| **PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING**<br><br>0x00000020 | Windows Essential Business Server Messaging Server |
| **PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY**<br><br>0x0000001F | Windows Essential Business Server Security Server |
| **PRODUCT_MOBILE_CORE**<br><br>0x00000068 | Windows 10 Mobile |
| **PRODUCT_MOBILE_ENTERPRISE**<br><br>0x00000085 | Windows 10 Mobile Enterprise |
| **PRODUCT_MULTIPOINT_PREMIUM_SERVER**<br><br>0x0000004D | Windows MultiPoint Server Premium (full installation) |
| **PRODUCT_MULTIPOINT_STANDARD_SERVER**<br><br>0x0000004C | Windows MultiPoint Server Standard (full installation) |
| **PRODUCT_PPI_PRO**<br><br>0x00000077 | Windows 10 Team |
| **PRODUCT_PRO_FOR_EDUCATION**<br><br>0x000000A4 | Windows 10 Pro Education |
| **PRODUCT_PRO_WORKSTATION**<br><br>0x000000A1 | Windows 10 Pro for Workstations |
| **PRODUCT_PRO_WORKSTATION_N**<br><br>0x000000A2 | Windows 10 Pro for Workstations N |
| **PRODUCT_PROFESSIONAL**<br><br>0x00000030 | Windows 10 Pro |
| **PRODUCT_PROFESSIONAL_E**<br><br>0x00000045 | Not supported |
| **PRODUCT_PROFESSIONAL_N**<br><br>0x00000031 | Windows 10 Pro N |
| **PRODUCT_PROFESSIONAL_WMC**<br><br>0x00000067 | Professional with Media Center |
| **PRODUCT_SB_SOLUTION_SERVER**<br><br>0x00000032 | Windows Small Business Server 2011 Essentials |
| **PRODUCT_SB_SOLUTION_SERVER_EM**<br><br>0x00000036 | Server For SB Solutions EM |
| **PRODUCT_SERVER_FOR_SB_SOLUTIONS**<br><br>0x00000033 | Server For SB Solutions |
| **PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM**<br><br>0x00000037 | Server For SB Solutions EM |
| **PRODUCT_SERVER_FOR_SMALLBUSINESS**<br><br>0x00000018 | Windows Server 2008 for Windows Essential Server Solutions |
| **PRODUCT_SERVER_FOR_SMALLBUSINESS_V**<br><br>0x00000023 | Windows Server 2008 without Hyper-V for Windows Essential Server Solutions |
| **PRODUCT_SERVER_FOUNDATION**<br><br>0x00000021 | Server Foundation |
| **PRODUCT_SERVERRDSH**<br><br>0x000000AF | Windows 10 Enterprise for Virtual Desktops |
| **PRODUCT_SMALLBUSINESS_SERVER**<br><br>0x00000009 | Windows Small Business Server |
| **PRODUCT_SMALLBUSINESS_SERVER_PREMIUM**<br><br>0x00000019 | Small Business Server Premium |
| **PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE**<br><br>0x0000003F | Small Business Server Premium (core installation) |
| **PRODUCT_SOLUTION_EMBEDDEDSERVER**<br><br>0x00000038 | Windows MultiPoint Server |
| **PRODUCT_STANDARD_EVALUATION_SERVER**<br><br>0x0000004F | Server Standard (evaluation installation) |
| **PRODUCT_STANDARD_SERVER**<br><br>0x00000007 | Server Standard (full installation. For Server Core installations of Windows Server 2012 and later, use the method, [Determining whether Server Core is running](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh846315(v=vs.85)).) |
| **PRODUCT_STANDARD_SERVER_CORE**<br><br>0x0000000D | Server Standard (core installation, Windows Server 2008 R2 and earlier) |
| **PRODUCT_STANDARD_SERVER_CORE_V**<br><br>0x00000028 | Server Standard without Hyper-V (core installation) |
| **PRODUCT_STANDARD_SERVER_V**<br><br>0x00000024 | Server Standard without Hyper-V |
| **PRODUCT_STANDARD_SERVER_SOLUTIONS**<br><br>0x00000034 | Server Solutions Premium |
| **PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE**<br><br>0x00000035 | Server Solutions Premium (core installation) |
| **PRODUCT_STARTER**<br><br>0x0000000B | Starter |
| **PRODUCT_STARTER_E**<br><br>0x00000042 | Not supported |
| **PRODUCT_STARTER_N**<br><br>0x0000002F | Starter N |
| **PRODUCT_STORAGE_ENTERPRISE_SERVER**<br><br>0x00000017 | Storage Server Enterprise |
| **PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE**<br><br>0x0000002E | Storage Server Enterprise (core installation) |
| **PRODUCT_STORAGE_EXPRESS_SERVER**<br><br>0x00000014 | Storage Server Express |
| **PRODUCT_STORAGE_EXPRESS_SERVER_CORE**<br><br>0x0000002B | Storage Server Express (core installation) |
| **PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER**<br><br>0x00000060 | Storage Server Standard (evaluation installation) |
| **PRODUCT_STORAGE_STANDARD_SERVER**<br><br>0x00000015 | Storage Server Standard |
| **PRODUCT_STORAGE_STANDARD_SERVER_CORE**<br><br>0x0000002C | Storage Server Standard (core installation) |
| **PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER**<br><br>0x0000005F | Storage Server Workgroup (evaluation installation) |
| **PRODUCT_STORAGE_WORKGROUP_SERVER**<br><br>0x00000016 | Storage Server Workgroup |
| **PRODUCT_STORAGE_WORKGROUP_SERVER_CORE**<br><br>0x0000002D | Storage Server Workgroup (core installation) |
| **PRODUCT_ULTIMATE**<br><br>0x00000001 | Ultimate |
| **PRODUCT_ULTIMATE_E**<br><br>0x00000047 | Not supported |
| **PRODUCT_ULTIMATE_N**<br><br>0x0000001C | Ultimate N |
| **PRODUCT_UNDEFINED**<br><br>0x00000000 | An unknown product |
| **PRODUCT_WEB_SERVER**<br><br>0x00000011 | Web Server (full installation) |
| **PRODUCT_WEB_SERVER_CORE**<br><br>0x0000001D | Web Server (core installation) |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. This function fails if one of the input parameters is invalid.

## Remarks

To detect whether a server role or feature is installed, use the [Server Feature](https://learn.microsoft.com/windows/desktop/WmiSdk/win32-serverfeature) WMI provider.

Subsequent releases of Windows will map the product types it supports to the set of product types supported by each supported previous release of Windows, back to version 6.0.0.0. Therefore, an application that does an equality test for any of these values will continue to work on future releases, even when new product types are added.

PRODUCT_*_SERVER_CORE values are not returned in Windows Server 2012, and later. For example, the base server edition, Server Datacenter, is used to build the two different installation options: "full server" and "core server". With Windows Server 2012, **GetProductInfo** will return PRODUCT_DATACENTER regardless of the option used during product installation. As noted above, for Server Core installations of Windows Server 2012 and later, use the method [Determining whether Server Core is running](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh846315(v=vs.85)).

The following table indicates the product types that were introduced in 6.1.0.0, and what they will map to if **GetProductInfo** is called with version 6.0.0.0 on a 6.1.0.0 system.

| New for 6.1.0.0 | Value returned with 6.0.0.0 |
| --- | --- |
| PRODUCT_PROFESSIONAL | PRODUCT_BUSINESS |
| PRODUCT_PROFESSIONAL_N | PRODUCT_BUSINESS_N |
| PRODUCT_STARTER_N | PRODUCT_STARTER |

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example, see [Getting the System Version](https://learn.microsoft.com/windows/desktop/SysInfo/getting-the-system-version).

## See also

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)