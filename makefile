app: WordData.o WordDataList.o WordCList.o WordSTLSeq.o app.o
		g++ -o app app.o WordData.o WordDataList.o WordCList.o WordSTLSeq.o -g

app.o: app.cpp WordData.h WordDataList.h WordCList.h WordSTLSeq.h
		g++ -c app.cpp -g

WordData.o: WordData.cpp WordData.h WordDataList.cpp WordDataList.h WordCList.cpp WordCList.h WordSTLSeq.cpp WordSTLSeq.h
		g++ -c WordData.cpp -g

WordDataList.o: WordDataList.cpp WordDataList.h
		g++ -c WordDataList.cpp -g

WordCList.o: WordCList.cpp WordCList.h CircularList.h
		g++ -c WordCList.cpp -g

WordVectorList.o: WordSTLSeq.cpp WordSTLSeq.h
		g++ -c WordSTLSeq.cpp -g

clean:
		rm -f *.o app

lie:
		echo "This is a great lecture"