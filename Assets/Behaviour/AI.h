

class AI
{
// ================================================
// Public Member Constructor
public:
	AI( GameBoard gameBoard ) { m_gameBoard = gameBoard; }
	~AI() { if (m_gameBoard) {delete m_gameBoard; m_gameBoard = NULL;} }

	void AIMoveX();
	void AIMoveO();

// ================================================
// Protected Member Functions
protected:


// ================================================
// Private Member Functions
private:
	void aiPickLocationOnGameBoard();

// ================================================
// Private Member Variables
private:
	GameBoard* m_gameBoard;

};