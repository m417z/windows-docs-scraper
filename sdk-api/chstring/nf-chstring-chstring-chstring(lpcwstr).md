# CHString::CHString(LPCWSTR)

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

Each of these constructors initializes a new [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object with the specified data.

## Parameters

### `lpsz`

A **NULL**-terminated string that is copied into this [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object.

## Remarks

Because the constructors copy the input data into new allocated storage, memory exceptions can result. Some of these constructors act as conversion functions; you can substitute, for example, an **LPWSTR** where a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) object is expected.

Several forms of the constructor have special purposes:

* CHString( LPCSTR
  *lpsz* )

  Constructs a Unicode [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string from an ANSI string.
* CHString( LPCWSTR
  *lpsz* )

  Constructs a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string from a Unicode string.
* CHString( const unsigned char*
  *psz*)

  Enables you to construct a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string from a pointer to unsigned char.

#### Examples

The following code example shows how to use [CHString::CHString](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-chstring(constchstring_)).

```cpp
CHString s1;                    // Empty string
CHString s2( L"cat" );          // From a C string literal
CHString s3 = s2;               // Copy constructor
CHString s4( s2 + " " + s3 );   // From a string expression

CHString s5( 'x' );             // s5 = "x"
CHString s6( 'x', 6 );          // s6 = "xxxxxx"

CHString city = L"Philadelphia"; // NOT the assignment operator
```