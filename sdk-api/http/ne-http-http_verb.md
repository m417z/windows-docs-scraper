# HTTP_VERB enumeration

## Description

The
**HTTP_VERB** enumeration type defines values that are used to specify known, standard HTTP verbs in the
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure. The majority of these known verbs are documented in [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt) and
[RFC 2518](https://www.ietf.org/rfc/rfc2518.txt), as indicated below.

## Constants

### `HttpVerbUnparsed`

Not relevant for applications; used only in kernel mode.

### `HttpVerbUnknown`

Indicates that the application can examine the **UnknownVerbLength** and **pUnknownVerb** members of the [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure to retrieve the HTTP verb for the request. This is the case in an HTTP/1.1 request when a browser client specifies a custom verb.

### `HttpVerbInvalid`

Not relevant for applications; used only in kernel mode.

### `HttpVerbOPTIONS`

The OPTIONS method requests information about the communication options and requirements associated with a URI.

 See page 52 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbGET`

The GET method retrieves the information or entity that is identified by the URI of the Request. If that URI refers to a script or other data-producing process, it is the data produced, not the text of the script, that is returned in the response.

A GET method can be made conditional or partial by including a conditional or Range header field in the request. A conditional GET requests that the entity be sent only if all conditions specified in the header are met, and a partial GET requests only part of the entity, as specified in the Range header. Both of these forms of GET can help avoid unnecessary network traffic.

 See page 53 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbHEAD`

The HEAD method is identical to GET except that the server only returns message-headers in the response, without a message-body. The headers are the same as would be returned in response to a GET.

 See page 54 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbPOST`

The POST method is used to post a new entity as an addition to a URI.
The URI identifies an entity that consumes the posted data in some fashion.

 See page 54 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbPUT`

The PUT method is used to replace an entity identified by a URI.

 See page 55 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbDELETE`

The
DELETE method requests that a specified URI be deleted.

 See page 56 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbTRACE`

The TRACE method invokes a remote, application-layer loop-back of the request message.
It allows the client to see what is being received at the other
end of the request chain for diagnostic
purposes. See page 56 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbCONNECT`

The CONNECT
method can be used with a proxy that can dynamically switch to tunneling, as in the case of SSL tunneling. See page 57 of [RFC 2616](https://www.ietf.org/rfc/rfc2616.txt).

### `HttpVerbTRACK`

The TRACK method is used by Microsoft Cluster Server to implement a non-logged trace.

### `HttpVerbMOVE`

The MOVE method requests a WebDAV operation
equivalent to a copy (COPY), followed by consistency maintenance
processing, followed by a delete of the source, where all three
actions are performed atomically. When applied to a collection, "Depth" is assumed to be or must be specified as "infinity". See page 42 of [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt).

### `HttpVerbCOPY`

The COPY method requests a WebDAV operation that creates a duplicate of the source resource,
identified by the Request URI, in the destination resource,
identified by a URI specified in the Destination header. See page 37 of [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt).

### `HttpVerbPROPFIND`

The PROPFIND method requests a WebDAV operation that retrieves properties defined on the resource
identified by the Request-URI. See page 24 of [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt).

### `HttpVerbPROPPATCH`

The PROPPATCH method requests a WebDAV operation that sets and/or removes properties defined on the resource
identified by the Request-URI. See page 31 of [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt).

### `HttpVerbMKCOL`

The MKCOL method requests a WebDAV operation that creates a new collection
resource at the location specified by
the Request-URI. See page 33 of [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt).

### `HttpVerbLOCK`

The LOCK method requests a WebDAV operation that creates a lock as specified by the lockinfo
XML element on the Request-URI. See page 45 of [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt).

### `HttpVerbUNLOCK`

The UNLOCK method requests a WebDAV operation that removes a lock, identified by a lock token in
the Lock-Token request header, from the resource identified by the Request-URI, and from all other
resources included in the lock. See page 51 of [RFC 2518](https://www.ietf.org/rfc/rfc2518.txt).

### `HttpVerbSEARCH`

The SEARCH method requests a WebDAV operation used by
Microsoft Exchange to search folders. See the Internet Engineering Task Force (IETF) Internet Draft WebDAV SEARCH for more information, and the [WebDAV Web site](http://www.webdav.org/) for possible updates.

### `HttpVerbMaximum`

Terminates the enumeration; is not used to define a verb.

## See also

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))