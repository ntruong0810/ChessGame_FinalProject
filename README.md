# King Chess

## I. Project Description

King Chess is a two-player chess game developed in C++ using the SFML graphics library.  
The project applies object-oriented programming (OOP) principles and interactive event handling to simulate the standard rules of chess, including valid piece movement, turn-based play, and checkmate detection.

---

## II. Key Features Implemented

- Fully functional chessboard rendered using SFML with a scalable sprite-based layout.
- Piece movement via drag-and-drop, with snapping and offset handling.
- Turn-based system, alternating between White and Black.
- Accurate move validation using polymorphic `MoveLogic` classes (Pawn, Rook, Knight, Bishop, Queen, King).
- Factory design pattern (`MoveLogicFactory`) to handle piece-specific movement logic.
- Check and checkmate detection via the `GameState` module.
- Safe piece capturing, with iterator-aware logic to avoid invalid memory access.
- Clean object-oriented design, separating responsibilities across `PieceManager`, `DragManager`, `TextureManager`, and `GameState`.

---

## III. Core Classes

- **PieceManager**: Manages current state and rendering of all pieces.
- **DragManager**: Handles user interactions, move validation, turn switching, and checkmate detection.
- **GameState**: Static class used to evaluate check/checkmate status.
- **MoveLogic + subclasses**: Abstract base class and specialized move logic for each piece type.
- **MoveLogicFactory**: Dynamically generates the correct logic class based on `PieceType`.
- **TextureManager**: Loads and slices the sprite sheet for visual representation.

---

## IV. Missing Features

- Pawn Promotion
- Castling (Kingside and Queenside)
- Stalemate Detection

---

## V. Challenges Encountered

One of the initial challenges was handling piece removal safely using `pieces.erase(...)`, which risked invalidating references or iterators. Careful ordering was required — moving pieces before deleting captured ones — to ensure data integrity.

Another difficulty involved implementing sliding piece logic for the Bishop and Rook. It required thinking in terms of direction vectors and stopping movement at obstructions, which became much clearer after drawing movement paths on paper.

Understanding SFML’s coordinate system also took effort, as it uses a top-left origin with the y-axis increasing downward. Lastly, simulating future board states to test for check and checkmate required cloning the board and checking king safety after hypothetical moves.

---

**Author:** Thu Nhan Truong — CS3A Final Project  
