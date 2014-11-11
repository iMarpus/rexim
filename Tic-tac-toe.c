#include <stdio.h>
#include <stdlib.h>

void writeMap(char **map);
int game(char **map,int count);
char winCheck(char **map);

int main()
{
	int i, j, count = 2;
	char FLAG = ' ';
	char **map;
	map = malloc(3*sizeof(char*));
  for (i = 0; i < 3; i++)
    map[i]=malloc(3*sizeof(char));
	for (i = 0; i < 3; i++) 
		{
			for (j = 0; j < 3; j++) map[i][j] = '*';
		}
	writeMap(map);
	do
	{
		count = game(map, count);
		FLAG = winCheck(map);
	}while((FLAG == ' ') && (count != 9)); 	
	printf("Winner is ");
	printf("%c", FLAG);
	return 0;
}

void writeMap(char **map)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)	printf(" %c", map[i][j]);
		printf("\n");
	}	
}

int game(char	**map,int count)
{
	int pointX, pointY;
  scanf("%d %d", &pointX, &pointY);
  pointX--;
  pointY--;
  if ((pointX > 2 || pointX < 0) && (pointY > 2 || pointY < 0))
  {
		printf("Enter another index!\n");
		return count;
	}
  if (map[pointX][pointY] != '*')
  {
		printf("Enter another index!\n");
		return count;
  }
  else
  {
		if(count%2==0)
			map[pointX][pointY] = 'X';
    else
			map[pointX][pointY] = 'O';
		count++;
	}
	writeMap(map);
	return count;
}

char winCheck(char **map)
{
	int i;
	for(i = 0; i < 3; i++)  
    if(map[i][0] == map[i][1] && map[i][0] == map[i][2])
      if (map[i][0] == 'X' || map[i][0] == 'O') return map[i][0];

  for(i = 0; i < 3; i++) 
    if(map[0][i] == map[1][i] && map[0][i] == map[2][i]) 
			if (map[0][i] == 'X' || map[0][i] == 'O') return map[0][i];

  if(map[0][0] == map[1][1] && map[1][1] == map[2][2]) 
		if (map[0][0] == 'X' || map[0][0] == 'O') return map[0][0];
 
  if(map[0][2] == map[1][1] && map[1][1] == map[2][0]) 
		if (map[1][1] == 'X' || map[1][1] == 'O') return map[1][1];
  
  return ' ';
}
