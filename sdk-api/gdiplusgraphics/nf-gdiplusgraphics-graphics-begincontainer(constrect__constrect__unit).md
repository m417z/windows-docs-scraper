# Graphics::BeginContainer(IN const Rect &,IN const Rect &,IN Unit)

## Description

The **Graphics::BeginContainer** method begins a new graphics container.

## Parameters

### `dstrect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that, together with *srcrect*, specifies a transformation for the container.

### `srcrect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that, together with *dstrect*, specifies a transformation for the container.

### `unit` [in]

Type: **[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)**

Unit of measure for the container.

## Return value

Type: **GraphicsContainer**

This method returns a value that identifies the container.

## Remarks

Use this method to create nested graphics containers. Graphics containers are used to retain graphics state, such as transformations, clipping regions, and various rendering properties.

The **Graphics::BeginContainer** method returns a value of type
[GraphicsContainer](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-graphics-containers-about). When you have finished using a container, pass that value to the [Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer) method. The
GraphicsContainer data type is defined in Gdiplusenums.h.

The
*dstrect* and
*srcrect* parameters specify a transformation. It is the transformation that, when applied to
*srcrect*, results in
*dstrect*.

When you call the **Graphics::BeginContainer** method of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, an information block that holds the state of the
**Graphics** object is put on a stack. The **Graphics::BeginContainer** method returns a value that identifies that information block. When you pass the identifying value to the [Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer) method, the information block is removed from the stack and is used to restore the
**Graphics** object to the state it was in at the time of the **Graphics::BeginContainer** call.

Containers can be nested; that is, you can call the **Graphics::BeginContainer** method several times before you call the [Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer) method. Each time you call the **Graphics::BeginContainer** method, an information block is put on the stack, and you receive an identifier for the information block. When you pass one of those identifiers to the **Graphics::EndContainer** method, the
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is returned to the state it was in at the time of the **Graphics::BeginContainer** call that returned that particular identifier. The information block placed on the stack by that **Graphics::BeginContainer** call is removed from the stack, and all information blocks placed on that stack after that **Graphics::BeginContainer** call are also removed.

Calls to the [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) method place information blocks on the same stack as calls to the **Graphics::BeginContainer** method. Just as an [Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer) call is paired with a **Graphics::BeginContainer** call, a [Graphics::Restore](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-restore) call is paired with a **Graphics::Save** call.

**Caution** When you call [Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer), all information blocks placed on the stack (by [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) or by **Graphics::BeginContainer**) after the corresponding call to **Graphics::BeginContainer** are removed from the stack. Likewise, when you call [Graphics::Restore](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-restore), all information blocks placed on the stack (by **Graphics::Save** or by **Graphics::BeginContainer**) after the corresponding call to **Graphics::Save** are removed from the stack.

For more information about graphics containers, see [Nested Graphics Containers](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-nested-graphics-containers-use).

#### Examples

The following example calls the **Graphics::BeginContainer** method to create a graphics container. The code specifies a transformation for the container by passing two rectangles to the **Graphics::BeginContainer** method. The code calls
[Graphics::FillEllipse](https://learn.microsoft.com/previous-versions/ms535966(v=vs.85)) twice: once inside the container and once outside the container (after the call to [Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer)).

```cpp
VOID Example_BeginContainer2(HDC hdc)
{
   Graphics graphics(hdc);

   // Define a translation and scale transformation for the container.
   Rect srcRect(0, 0, 200, 100);
   Rect destRect(100, 100, 200, 200);

   // Create a graphics container with a (100, 100) translation
   // and (1, 2) scale.
   GraphicsContainer container;
   container = graphics.BeginContainer(destRect, srcRect, UnitPixel);

   // Fill an ellipse in the container.
   SolidBrush redBrush(Color(255, 255, 0, 0));
   graphics.FillEllipse(&redBrush, 0, 0, 100, 60);

   // End the container.
   graphics.EndContainer(container);

   // Fill the same ellipse outside the container.
   SolidBrush blueBrush(Color(255, 0, 0, 255));
   graphics.FillEllipse(&blueBrush, 0, 0, 100, 60);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Containers](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-graphics-containers-about)

[Graphics::EndContainer](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-endcontainer)

[Graphics::Restore](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-restore)

[Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save)

[Using Graphics Containers](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-graphics-containers-use)