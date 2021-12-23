class voiture{
	int Id;
	string matricule;
	int nbr_porte;
	int nbr_places;
	string color;
	
	int MarqueId;
	Marque marque;
	
	int AssuranceId;
	List<Assurance> assurances;
	
	List<Client> clients; 
	
};


class Marque{
	int Id;
	string libelle;
	
	List<Voiture> voitures; 
};


class Assurance{
	
	int Id;
	string agence;
	
	int VoitureId;
	Voiture voiture;
	
}

class Client{
	int Id;
	string nom;
	string prenom;
	
	List<Voiture> voitures; 
};


class Location{
	
	[key]
	[Column(order=1)]
	int Id;
	
	[key]
	[Column(order=2)]
	int ClientId;
	
	[key]
	[Column(order=3)]
	int VoitureId;
	
	
	
	
};
