# WinHttpQueryAuthSchemes function

## Description

The **WinHttpQueryAuthSchemes** function returns the authorization schemes that are supported by the server.

## Parameters

### `hRequest` [in]

Valid
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)

### `lpdwSupportedSchemes` [out]

An unsigned integer that specifies a flag that contains the supported authentication schemes. This parameter can return one or more flags that are identified in the following table.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTH_SCHEME_BASIC** | Indicates basic authentication is available. |
| **WINHTTP_AUTH_SCHEME_NTLM** | Indicates NTLM authentication is available. |
| **WINHTTP_AUTH_SCHEME_PASSPORT** | Indicates passport authentication is available. |
| **WINHTTP_AUTH_SCHEME_DIGEST** | Indicates digest authentication is available. |
| **WINHTTP_AUTH_SCHEME_NEGOTIATE** | Selects between NTLM and Kerberos authentication. |

### `lpdwFirstScheme` [out]

An unsigned integer that specifies a flag that contains the first authentication scheme listed by the server. This parameter can return one or more flags that are identified in the following table.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTH_SCHEME_BASIC** | Indicates basic authentication is first. |
| **WINHTTP_AUTH_SCHEME_NTLM** | Indicates NTLM authentication is first. |
| **WINHTTP_AUTH_SCHEME_PASSPORT** | Indicates passport authentication is first. |
| **WINHTTP_AUTH_SCHEME_DIGEST** | Indicates digest authentication is first. |
| **WINHTTP_AUTH_SCHEME_NEGOTIATE** | Selects between NTLM and Kerberos authentication. |

### `pdwAuthTarget` [out]

An unsigned integer that specifies a flag that contains the authentication target. This parameter can return one or more flags that are identified in the following table.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTH_TARGET_SERVER** | Authentication target is a server. Indicates that a 401 status code has been received. |
| **WINHTTP_AUTH_TARGET_PROXY** | Authentication target is a proxy. Indicates that a 407 status code has been received. |

## Return value

Returns **TRUE** if successful, or **FALSE** if unsuccessful. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following table identifies the error codes that are returned.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** is set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**WinHttpQueryAuthSchemes** cannot be used before calling
[WinHttpQueryHeaders](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryheaders).

**Note** For Windows XP and Windows 2000 see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

#### Examples

The following example shows how to retrieve a specified document from an HTTP server when authentication is required. The status code is retrieved from the response to determine if the server or proxy is requesting authentication. If a 200 status code is found, the document is available. If a status code of 401 or 407 is found, authentication is required before the document can be retrieved. For any other status code an error message is displayed.

```cpp
#include <windows.h>
#include <winhttp.h>
#include <stdio.h>

#pragma comment(lib, "winhttp.lib")

DWORD ChooseAuthScheme( DWORD dwSupportedSchemes )
{
  //  It is the server's responsibility only to accept
  //  authentication schemes that provide a sufficient level
  //  of security to protect the server's resources.
  //
  //  The client is also obligated only to use an authentication
  //  scheme that adequately protects its username and password.
  //
  //  Thus, this sample code does not use Basic authentication
  //  because Basic authentication exposes the client's username
  //  and password to anyone monitoring the connection.

  if( dwSupportedSchemes & WINHTTP_AUTH_SCHEME_NEGOTIATE )
    return WINHTTP_AUTH_SCHEME_NEGOTIATE;
  else if( dwSupportedSchemes & WINHTTP_AUTH_SCHEME_NTLM )
    return WINHTTP_AUTH_SCHEME_NTLM;
  else if( dwSupportedSchemes & WINHTTP_AUTH_SCHEME_PASSPORT )
    return WINHTTP_AUTH_SCHEME_PASSPORT;
  else if( dwSupportedSchemes & WINHTTP_AUTH_SCHEME_DIGEST )
    return WINHTTP_AUTH_SCHEME_DIGEST;
  else
    return 0;
}

struct SWinHttpSampleGet
{
  LPCWSTR szServer;
  LPCWSTR szPath;
  BOOL fUseSSL;
  LPCWSTR szServerUsername;
  LPCWSTR szServerPassword;
  LPCWSTR szProxyUsername;
  LPCWSTR szProxyPassword;
};

void WinHttpAuthSample( IN SWinHttpSampleGet *pGetRequest )
{
  DWORD dwStatusCode = 0;
  DWORD dwSupportedSchemes;
  DWORD dwFirstScheme;
  DWORD dwSelectedScheme;
  DWORD dwTarget;
  DWORD dwLastStatus = 0;
  DWORD dwSize = sizeof(DWORD);
  BOOL  bResults = FALSE;
  BOOL  bDone = FALSE;

  DWORD dwProxyAuthScheme = 0;
  HINTERNET  hSession = NULL,
             hConnect = NULL,
             hRequest = NULL;

  // Use WinHttpOpen to obtain a session handle.
  hSession = WinHttpOpen( L"WinHTTP Example/1.0",
                          WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                          WINHTTP_NO_PROXY_NAME,
                          WINHTTP_NO_PROXY_BYPASS, 0 );

  INTERNET_PORT nPort = ( pGetRequest->fUseSSL ) ?
                        INTERNET_DEFAULT_HTTPS_PORT  :
                        INTERNET_DEFAULT_HTTP_PORT;

  // Specify an HTTP server.
  if( hSession )
    hConnect = WinHttpConnect( hSession,
                               pGetRequest->szServer,
                               nPort, 0 );

  // Create an HTTP request handle.
  if( hConnect )
    hRequest = WinHttpOpenRequest( hConnect,
                                   L"GET",
                                   pGetRequest->szPath,
                                   NULL,
                                   WINHTTP_NO_REFERER,
                                   WINHTTP_DEFAULT_ACCEPT_TYPES,
                                   ( pGetRequest->fUseSSL ) ?
                                       WINHTTP_FLAG_SECURE : 0 );

  // Continue to send a request until status code is not 401 or 407.
  if( hRequest == NULL )
    bDone = TRUE;

  while( !bDone )
  {
    //  If a proxy authentication challenge was responded to, reset
    //  those credentials before each SendRequest, because the proxy
    //  may require re-authentication after responding to a 401 or to
    //  a redirect. If you don't, you can get into a 407-401-407-401
    //  loop.
    if( dwProxyAuthScheme != 0 )
      bResults = WinHttpSetCredentials( hRequest,
                                        WINHTTP_AUTH_TARGET_PROXY,
                                        dwProxyAuthScheme,
                                        pGetRequest->szProxyUsername,
                                        pGetRequest->szProxyPassword,
                                        NULL );
    // Send a request.
    bResults = WinHttpSendRequest( hRequest,
                                   WINHTTP_NO_ADDITIONAL_HEADERS,
                                   0,
                                   WINHTTP_NO_REQUEST_DATA,
                                   0,
                                   0,
                                   0 );

    // End the request.
    if( bResults )
      bResults = WinHttpReceiveResponse( hRequest, NULL );

    // Resend the request in case of
    // ERROR_WINHTTP_RESEND_REQUEST error.
    if( !bResults && GetLastError( ) == ERROR_WINHTTP_RESEND_REQUEST)
        continue;

    // Check the status code.
    if( bResults )
      bResults = WinHttpQueryHeaders( hRequest,
                                      WINHTTP_QUERY_STATUS_CODE |
                                          WINHTTP_QUERY_FLAG_NUMBER,
                                      NULL,
                                      &dwStatusCode,
                                      &dwSize,
                                      NULL );

    if( bResults )
    {
      switch( dwStatusCode )
      {
        case 200:
          // The resource was successfully retrieved.
          // You can use WinHttpReadData to read the contents
          // of the server's response.
          printf( "The resource was successfully retrieved.\n" );
          bDone = TRUE;
          break;

        case 401:
          // The server requires authentication.
          printf(
           "The server requires authentication. Sending credentials\n");

          // Obtain the supported and preferred schemes.
          bResults = WinHttpQueryAuthSchemes( hRequest,
                                              &dwSupportedSchemes,
                                              &dwFirstScheme,
                                              &dwTarget );

          // Set the credentials before re-sending the request.
          if( bResults )
          {
            dwSelectedScheme = ChooseAuthScheme( dwSupportedSchemes );

            if( dwSelectedScheme == 0 )
              bDone = TRUE;
            else
              bResults = WinHttpSetCredentials(
                                        hRequest, dwTarget,
                                        dwSelectedScheme,
                                        pGetRequest->szServerUsername,
                                        pGetRequest->szServerPassword,
                                        NULL );
          }

          // If the same credentials are requested twice, abort the
          // request.  For simplicity, this sample does not check for
          // a repeated sequence of status codes.
          if( dwLastStatus == 401 )
            bDone = TRUE;

          break;

        case 407:
          // The proxy requires authentication.
          printf(
           "The proxy requires authentication. Sending credentials\n");

          // Obtain the supported and preferred schemes.
          bResults = WinHttpQueryAuthSchemes( hRequest,
                                              &dwSupportedSchemes,
                                              &dwFirstScheme,
                                              &dwTarget );

          // Set the credentials before re-sending the request.
          if( bResults )
            dwProxyAuthScheme = ChooseAuthScheme(dwSupportedSchemes);

          // If the same credentials are requested twice, abort the
          // request.  For simplicity, this sample does not check for
          // a repeated sequence of status codes.
          if( dwLastStatus == 407 )
            bDone = TRUE;
          break;

        default:
          // The status code does not indicate success.
          printf( "Error. Status code %d returned.\n", dwStatusCode );
          bDone = TRUE;
      }
    }

    // Keep track of the last status code.
    dwLastStatus = dwStatusCode;

    // If there are any errors, break out of the loop.
    if( !bResults )
        bDone = TRUE;
  }

  // Report any errors.
  if( !bResults )
  {
    DWORD dwLastError = GetLastError( );
    printf( "Error %d has occurred.\n", dwLastError );
  }

  // Close any open handles.
  if( hRequest ) WinHttpCloseHandle( hRequest );
  if( hConnect ) WinHttpCloseHandle( hConnect );
  if( hSession ) WinHttpCloseHandle( hSession );
}

```

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpSetCredentials](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetcredentials)