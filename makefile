PDF: PDFLATEX
	evince sec.pdf&

PDFLATEX: LATEX2
	pdflatex sec


LATEX2: NOMENCLATURA
	latex sec


NOMENCLATURA: LATEX1 sec.nlo
	makeindex sec.nlo -s nomencl.ist -o sec.nls

LATEX1: sec.tex macros.tex
	latex sec


clear: *.aux *.bbl *.dvi *.pdf
	rm *.aux
	rm *.bbl
	rm *.blg
	rm *.dvi
	rm *.ilg
	rm *.lof
	rm *.log
	rm *.lot
	rm *.nlo
	rm *.nls
	rm *.out
	rm *.pdf
	rm *.toc
