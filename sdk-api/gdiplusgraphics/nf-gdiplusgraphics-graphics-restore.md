# Graphics::Restore

## Description

The **Graphics::Restore** method sets the state of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to the state stored by a previous call to the [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) method of this **Graphics** object.

## Parameters

### `gstate` [in]

Type: **GraphicsState**

32-bit value (returned by a previous call to the [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) method of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object) that identifies a block of saved state.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

When you call the [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) method of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, an information block that holds the state of the **Graphics** object is put on a stack. The **Graphics::Save** method returns a value that identifies that information block. When you pass the identifying value to the **Restore** method, the information block is removed from the stack and is used to restore the **Graphics** object to the state it was in at the time of the **Graphics::Save** call. Note that the identifier returned by a given call to the **Graphics::Save** method can be passed only once to the **Graphics::Restore** method.

Calls to the [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) method can be nested; that is, you can call the **Graphics::Save** method several times before you call the **Graphics::Restore** method. Each time you call the **Graphics::Save** method, an information block is put on the stack, and you receive an identifier for the information block. When you pass one of those identifiers to the **Graphics::Restore** method, the [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object is returned to the state it was in at the time of the **Graphics::Save** call that returned that particular identifier. The information block placed on the stack by that **Graphics::Save** call is removed from the stack, and all information blocks placed on that stack after that **Graphics::Save** call are also removed.

Calls to the **BeginContainer** method place information blocks on the same stack as calls to the [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) method. Just as a **Graphics::Restore** call is paired with a **Graphics::Save** call, an **EndContainer** call is paired with a **BeginContainer** call.

**Note** When you call **Graphics::Restore**, all information blocks placed on the stack (by [Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save) or by **BeginContainer**) after the corresponding call to **Graphics::Save** are removed from the stack. Likewise, When you call **EndContainer**, all information blocks placed on the stack (by **Graphics::Save** or by **BeginContainer**) after the corresponding call to **BeginContainer** are removed from the stack.

#### Examples

The following examples show two ways to use the **Graphics::Restore** method. The first example shows how to restore nested saved states, and the second example shows how to restore only the first of two nested saved states.

**Restoring Nested Saved States**

The following example sets the world transformation of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to a rotation and then saves the state of the **Graphics** object. Next, the code calls **TranslateTransform**, and saves the state again. Then the code calls **ScaleTransform**. At that point, the world transformation of the **Graphics** object is a composite transformation: first rotate, then translate, then scale. The code uses a red pen to draw an ellipse that is transformed by that composite transformation.

The code passes *state2*, which was returned by the second call to **Save**, to the **Graphics::Restore** method, and draws the ellipse again using a green pen. The green ellipse is rotated and translated but not scaled. Finally the code passes state1, which was returned by the first call to **Save**, to the **Graphics::Restore** method, and draws the ellipse again using a blue pen. The blue ellipse is rotated but not translated or scaled.

```cpp
VOID Example_Save1(HDC hdc)
{
   Graphics graphics(hdc);
   GraphicsState state1, state2;

   graphics.RotateTransform(30.0f);
   state1 = graphics.Save();
   graphics.TranslateTransform(100.0f, 0.0f, MatrixOrderAppend);
   state2 = graphics.Save();
   graphics.ScaleTransform(1.0f, 3.0f, MatrixOrderAppend);

   // Draw an ellipse.
   // Three transformations apply: rotate, then translate, then scale.
   Pen redPen(Color(255, 255, 0, 0));
   graphics.DrawEllipse(&redPen, 0, 0, 100, 20);

   // Restore to state2 and draw the ellipse again.
   // Two transformations apply: rotate then translate.
   graphics.Restore(state2);
   Pen greenPen(Color(255, 0, 255, 0));
   graphics.DrawEllipse(&greenPen, 0, 0, 100, 20);

   // Restore to state1 and draw the ellipse again.
   // Only the rotation transformation applies.
   graphics.Restore(state1);
   Pen bluePen(Color(255, 0, 0, 255));
   graphics.DrawEllipse(&bluePen, 0, 0, 100, 20);
}

```

**Restoring Only the First of Two Nested Saved States**

The following example sets the world transformation of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to a rotation and then saves the state of the **Graphics** object. Next, the code calls **TranslateTransform**, and saves the state again. Then the code calls **ScaleTransform**. At that point, the world transformation of the **Graphics** object is a composite transformation: first rotate, then translate, then scale. The code uses a red pen to draw an ellipse that is transformed by that composite transformation.

The code passes *state1*, which was returned by the first call to **Save**, to the **Graphics::Restore** method, and draws the ellipse again using a green pen. The green ellipse is rotated but not translated or scaled.

Next the code attempts to restore the state identified by *state2*. The attempt fails because the call Restore(*state1*) removed the information blocks identified by both *state1* and *state2* from the stack.

```cpp
VOID Example_Save2(HDC hdc)
{
   Graphics graphics(hdc);
   GraphicsState state1, state2;

   graphics.RotateTransform(30.0f);
   state1 = graphics.Save();
   graphics.TranslateTransform(100.0f, 0.0f, MatrixOrderAppend);
   state2 = graphics.Save();
   graphics.ScaleTransform(1.0f, 3.0f, MatrixOrderAppend);

   // Draw an ellipse.
   // Three transformations apply: rotate, then translate, then scale.
   Pen redPen(Color(255, 255, 0, 0));
   graphics.DrawEllipse(&redPen, 0, 0, 100, 20);

   // Restore to state1 and draw the ellipse again.
   // Only the rotation transformation applies.
   graphics.Restore(state1);
   Pen greenPen(Color(255, 0, 255, 0));
   graphics.DrawEllipse(&greenPen, 0, 0, 100, 20);

   // The information block identified by state2 has been lost.
   // The following call to Restore has no effect because
   // Restore(state1) removed from the stack the
   // information blocks identified by state1 and state2.
   graphics.Restore(state2);

   // The Graphics object is still in the state identified by state1.
   // The following code draws a blue ellipse on top of the previously
   // drawn green ellipse.
   Pen bluePen(Color(255, 0, 0, 255));
   graphics.DrawEllipse(&bluePen, 0, 0, 100, 20);
}

```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::Save](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-save)