# INTERNET_PER_CONN_OPTIONW structure

## Description

Contains the value of an option.

## Members

### `dwOption`

Option to be queried or set. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INTERNET_PER_CONN_AUTOCONFIG_URL** | Sets or retrieves a string containing the URL to the automatic configuration script. |
| **INTERNET_PER_CONN_AUTODISCOVERY_FLAGS** | Sets or retrieves the automatic discovery settings. The **Value** member will contain one or more of the following values: <br><br>AUTO_PROXY_FLAG_ALWAYS_DETECT<br><br>Always automatically detect settings.<br><br>AUTO_PROXY_FLAG_CACHE_INIT_RUN<br><br>Indicates that the cached results of the automatic proxy configuration script should be used, instead of actually running the script, unless the cached file has expired.<br><br>AUTO_PROXY_FLAG_DETECTION_RUN<br><br>Automatic detection has been run at least once on this connection.<br><br>AUTO_PROXY_FLAG_DETECTION_SUSPECT<br><br>Not currently supported.<br><br>AUTO_PROXY_FLAG_DONT_CACHE_PROXY_RESULT<br><br>Do not allow the caching of the result of the automatic proxy configuration script.<br><br>AUTO_PROXY_FLAG_MIGRATED<br><br>The setting was migrated from a Microsoft Internet Explorer 4.0 installation, and automatic detection should be attempted once.<br><br>AUTO_PROXY_FLAG_USER_SET<br><br>The user has explicitly set the automatic detection. |
| **INTERNET_PER_CONN_FLAGS** | Sets or retrieves the connection type. The **Value** member will contain one or more of the following values: <br><br>PROXY_TYPE_DIRECT<br><br>The connection does not use a proxy server.<br><br>PROXY_TYPE_PROXY<br><br>The connection uses an explicitly set proxy server.<br><br>PROXY_TYPE_AUTO_PROXY_URL<br><br>The connection downloads and processes an automatic configuration script at a specified URL.<br><br>PROXY_TYPE_AUTO_DETECT<br><br>The connection automatically detects settings. |
| **INTERNET_PER_CONN_PROXY_BYPASS** | Sets or retrieves a string containing the URLs that do not use the proxy server. |
| **INTERNET_PER_CONN_PROXY_SERVER** | Sets or retrieves a string containing the proxy servers. |
| **INTERNET_PER_CONN_AUTOCONFIG_SECONDARY_URL** | Chained autoconfig URL. Used when the primary autoconfig URL points to an INS file that sets a second autoconfig URL for proxy information. |
| **INTERNET_PER_CONN_AUTOCONFIG_RELOAD_DELAY_MINS** | of minutes until automatic refresh of autoconfig URL by autodiscovery. |
| **INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_TIME** | Read only option. Returns the time the last known good autoconfig URL was found using autodiscovery. |
| **INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_URL** | Read only option. Returns the last known good URL found using autodiscovery. |

**Windows 7 and later:**

Clients that support Internet Explorer 8 should query the connection type using **INTERNET_PER_CONN_FLAGS_UI**. If this query fails, then the system is running a previous version of Internet Explorer and the client should query again with **INTERNET_PER_CONN_FLAGS**.

Restore the connection type using **INTERNET_PER_CONN_FLAGS** regardless of the version of Internet Explorer.

| Value | Meaning |
| --- | --- |
| **INTERNET_PER_CONN_FLAGS_UI** | Sets or retrieves the connection type. The **Value** member will contain one or more of the following values: <br><br>PROXY_TYPE_DIRECT<br><br>The connection does not use a proxy server.<br><br>PROXY_TYPE_PROXY<br><br>The connection uses an explicitly set proxy server.<br><br>PROXY_TYPE_AUTO_PROXY_URL<br><br>The connection downloads and processes an automatic configuration script at a specified URL.<br><br>PROXY_TYPE_AUTO_DETECT<br><br>The connection automatically detects settings. |

### `Value`

Union that contains the value for the option. It can be any one of the following types depending on the value of
**dwOption**:

#### dwValue

Unsigned long integer value.

#### pszValue

Pointer to a string value.

#### ftValue

A
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `dwValue`

### `pszValue`

### `ftValue`

##### - Value.dwValue

Unsigned long integer value.

##### - Value.ftValue

A
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

##### - Value.pszValue

Pointer to a string value.

## Remarks

In Internet Explorer 5, only the ANSI versions of
[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona) and
[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona) will work with the
**INTERNET_PER_CONN_OPTION** structure. The Unicode versions will support the
**INTERNET_PER_CONN_OPTION** structure in later versions of Internet Explorer.

For queries that return strings,
[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona) allocates the memory for the
**pszValue** member of the structure. The calling application must free this memory using the
[GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function when it has finished using the string.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines INTERNET_PER_CONN_OPTION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[INTERNET_PER_CONN_OPTION_LIST](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-internet_per_conn_option_lista)

[InternetQueryOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetqueryoptiona)

[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona)