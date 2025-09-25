## Description

The **WSPDATA** structure contains service provider information.

## Members

```C++
} WSPDATA, *LPWSPDATA;
```

### `wVersion`

Version of the Windows Sockets SPI specification that the Windows Sockets service provider expects the caller to use.

### `wHighVersion`

Highest version of the Windows Sockets SPI specification that this service provider can support (also encoded as above). Normally this will be the same as **wVersion**.

### `szDescription`

Null-terminated Unicode string into which the Windows Sockets provider copies a description of itself. The text (up to 256 characters in length) can contain any characters except control and formatting characters: the most likely use to which an SPI client will put this is to display it (possibly truncated) in a status message.

## Remarks

## See also

**[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)**